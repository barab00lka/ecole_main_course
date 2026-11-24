#include <stdio.h>
#include "my_matrix.h"
#include <time.h>
#include <threads.h>


void populate_matrix(matrix_t *result);
void output_matrix(matrix_t *M);
int my_mult_matrix_mt(matrix_t *A, matrix_t *B, matrix_t *result);

int main(void){

  matrix_t A, B;
  matrix_t res;
 matrix_t newres;
  my_create_matrix(1000,1000,&A);
  populate_matrix(&A);

  my_create_matrix(1000,1000,&B);
  populate_matrix(&B);
  // output_matrix(&B);

  clock_t start = clock();
  my_mult_matrix(&A, &B, &res);
  // output_matrix(&res);
	clock_t end = clock();
	double ms_1t = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

  start = clock();
  my_mult_matrix_mt(&A, &B, &newres);
	end = clock();
	double ms_mt = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
  // output_matrix(&newres);

  printf("\n\n1T == MT matrix multiplication? %s\n", (my_eq_matrix(&res,&newres) == SUCCESS) ?  "YES" : "NO");

 printf("\n1T multiplication Time: %.3f ms\n", ms_1t);
 printf("MT multiplication Time: %.3f ms\n", ms_mt);

  my_remove_matrix(&A), my_remove_matrix(&B);
   // my_remove_matrix(&res);
   my_remove_matrix(&newres);

}
void output_matrix(matrix_t *M) {
  printf("\n\n");
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      printf("%lf", M->matrix[i][j]);
      if (j != M->columns - 1) printf(" ");
    }
    if (i != M->rows - 1) printf("\n");
  }
}

typedef struct MulData {
	int start_Arow; // cстартовая строка с которой поток начнет вычислять
	int end_Arow; // диапазон

	const matrix_t *A, *B; 
	matrix_t *R;
} Mult_data;


static int thread_mul_it(void* arg){
		
	Mult_data *data = (Mult_data *)arg;

	for (int n = data->start_Arow; n < data->end_Arow; ++n)
    	for (int i = 0; i < data->A->columns; ++i)
    	  for (int j = 0; j < data->B->columns; ++j)
    	    data->R->matrix[n][j] += data->A->matrix[n][i] * data->B->matrix[i][j];

 return 0;
}

static void mul_mats_mt(const matrix_t *A, const matrix_t *B, matrix_t *R) {

	Mult_data mdata[8];
	thrd_t threads[8];
	
	int steps = A->rows / 8; 

  for (int thr = 0; thr < 8; ++thr){ 

	  Mult_data* cur_thread_data = mdata + thr; // создается структура в массиве структур потоков под интексом THR

	  cur_thread_data->start_Arow = thr * steps;
	  cur_thread_data->end_Arow = (thr+1) * steps;

	  cur_thread_data->A = A, cur_thread_data->B = B, cur_thread_data->R = R;
	  thrd_create(threads + thr, thread_mul_it, cur_thread_data); 
	  /* Если join вызвать сразу после thrd_create внутри цикла — тогда да, следующий поток создаётся только после завершения предыдущего, и параллельности нет. */
	   // thrd_join(threads[i],NULL);
  }

  for (int thr = 0; thr < 8; ++thr)
	  thrd_join(threads[thr],NULL);
}

int my_mult_matrix_mt(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK ||
           ROW_COL_MORE_THAN_ZERO(B->rows, B->columns) != OK)
    return INCORRECT_MATRIX;
  if (!(A->columns == B->rows)) return CALCULATION_ERROR;

  int status = OK;
  status = my_create_matrix(A->rows, B->columns, result);
  mul_mats_mt(A, B, result);

  return status;
}

void populate_matrix(matrix_t *result) {
  double cnt = 0.0;
 srand(time(NULL));
  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++) result->matrix[i][j] = ++cnt + (double)rand() / RAND_MAX ;
     // for (int j = 0; j < result->columns; j++) result->matrix[i][j] = ++cnt;
}


