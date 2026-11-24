#include <threads.h>
#include <assert.h>

#include "../my_matrix.h"

enum action { CHOOSE_ADD, CHOOSE_SUB };

static int eq_n(const matrix_t *A, const matrix_t *B) {
  return (A->columns == B->columns && A->rows == B->rows);
}

static int is_mul(const matrix_t *A, const matrix_t *B) {
  return A->columns == B->rows;
}

static int is_square(const matrix_t *M) { return (M->rows == M->columns); }

static void sum_mats(const matrix_t *A, const matrix_t *B, matrix_t *R) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j)
      R->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
}

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK ||
           ROW_COL_MORE_THAN_ZERO(B->rows, B->columns) != OK)
    return INCORRECT_MATRIX;
  if (!eq_n(A, B)) return CALCULATION_ERROR;

  int status = OK;
  status = my_create_matrix(A->rows, B->columns, result);
  sum_mats(A, B, result);

  return status;
}

static void sub_mats(const matrix_t *A, const matrix_t *B, matrix_t *R) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j)
      R->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
}

int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK ||
           ROW_COL_MORE_THAN_ZERO(B->rows, B->columns) != OK)
    return INCORRECT_MATRIX;
  if (!eq_n(A, B)) return CALCULATION_ERROR;

  int status = OK;
  status = my_create_matrix(A->rows, B->columns, result);
  sub_mats(A, B, result);

  return status;
}

static void mul_num_matrix(const matrix_t *A, double num, matrix_t *R) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j)
      R->matrix[i][j] = A->matrix[i][j] * num;
}

int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!A || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK)
    return INCORRECT_MATRIX;

  int status = OK;
  status = my_create_matrix(A->rows, A->columns, result);
  mul_num_matrix(A, number, result);

  return status;
}

static void mul_mats(const matrix_t *A, const matrix_t *B, matrix_t *R) {
  for (int n = 0; n < A->rows; ++n)
    for (int i = 0; i < A->columns; ++i)
      for (int j = 0; j < B->columns; ++j)
        R->matrix[n][j] += A->matrix[n][i] * B->matrix[i][j];
}

// typedef struct MulData {
// 	int Arow;
// 	const matrix_t *A, *B;
// 	matrix_t *R;
// } Mult_data;

// static int thread_mul_it(void* arg){

// 	Mult_data *data = (Mult_data *)arg;

//     for (int i = 0; i < data->A->columns; ++i)
//       for (int j = 0; j < data->B->columns; ++j)
//         data->R->matrix[data->Arow][j] += data->A->matrix[data->Arow][i] *
//         data->B->matrix[i][j];

//  return 0;
// }

// static void mul_mats_mt(const matrix_t *A, const matrix_t *B, matrix_t *R) {

// 	Mult_data mdata[A->rows];
// 	thrd_t threads[A->rows];

//   for (int i = 0; i < A->rows; ++i){
// 	  Mult_data* cur_thread_data = (mdata + i);
// 	  cur_thread_data->Arow = i;
// 	  cur_thread_data->A = A, cur_thread_data->B = B, cur_thread_data->R =
// R;

// 	  thrd_create(threads + i, thread_mul_it, cur_thread_data);
// 	  /* Если join вызвать сразу после thrd_create внутри цикла — тогда да,
// следующий поток создаётся только после завершения предыдущего, и
// параллельности нет.
// 	   *
// 	   thrd_join(threads[i],NULL);
// 	   */
//   }
//   for (int i = 0; i < A->rows; ++i)
// 	  thrd_join(threads[i],NULL);
// }

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK ||
           ROW_COL_MORE_THAN_ZERO(B->rows, B->columns) != OK)
    return INCORRECT_MATRIX;
  if (!is_mul(A, B)) return CALCULATION_ERROR;

  int status = OK;
  status = my_create_matrix(A->rows, B->columns, result);
  mul_mats(A, B, result);

  return status;
}

static void transpose(const matrix_t *A, matrix_t *R) {
  for (int Ar = 0; Ar < A->rows; ++Ar)
    for (int Ac = 0; Ac < A->columns; ++Ac)
      R->matrix[Ac][Ar] = A->matrix[Ar][Ac];
}

int my_transpose(matrix_t *A, matrix_t *result) {
  if (!A || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK)
    return INCORRECT_MATRIX;

  int status = OK;
  status = my_create_matrix(A->columns, A->rows, result);
  transpose(A, result);
  return status;
}

static int create_minor_matrix(matrix_t *src, matrix_t *new, int skip_row,
                               int skip_col) {
  int status = my_create_matrix((src->rows - 1), (src->columns - 1), new);

  if (status == OK)
    for (int i = 0, ni = 0; i < src->rows; ++i, ++ni) {
      if (i != skip_row) {
	 for (int j = 0, nj = 0; j < src->columns; ++j)
     	   if (j != skip_col)
     	     new->matrix[ni][nj++] = src->matrix[i][j];
     	 }
      else if (i == skip_row) 
	  --ni;
    }
  return status;
}


// Using Gaussian elimination O(n^3). By HubertFurr
static double find_det_gauss(matrix_t *M, int *status) {

    if (M->rows == 0) return 1.0;
    else if (M->rows == 1) return M->matrix[0][0];
    else if (M->rows == 2)
        return M->matrix[0][0] * M->matrix[1][1] - M->matrix[0][1] * M->matrix[1][0];

    matrix_t temp = {0};
    *status = my_copy_matrix_fast(M, &temp);
    if (*status != OK) return 0.0;

    double det = 1.0;
    int n = M->rows;

    for (int i = 0; i < n; ++i) {
        // Partial pivoting: поиск строки с максимальным элементом в столбце i
        int pivot_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(temp.matrix[j][i]) > fabs(temp.matrix[pivot_row][i])) {
                pivot_row = j;
            }
        }

        // Если ведущий элемент близок к нулю — матрица вырождена
        if (fabs(temp.matrix[pivot_row][i]) < EPS) {
            det = 0.0;
            break;
        }

        // Обмен строк (если нужно) и смена знака определителя
        if (pivot_row != i) {
            double *tmp_ptr = temp.matrix[i];
            temp.matrix[i] = temp.matrix[pivot_row];
            temp.matrix[pivot_row] = tmp_ptr;
        }

        // Умножаем определитель на ведущий элемент
        det *= temp.matrix[i][i];

        // Учёт смены знака при перестановке строк
        if (pivot_row != i) {
            det = -det;
        }

        // Исключение Гаусса: зануляем строки ниже i
        for (int j = i + 1; j < n; ++j) {
            double koef = temp.matrix[j][i] / temp.matrix[i][i];
            for (int k = i; k < n; ++k) {
                temp.matrix[j][k] -= temp.matrix[i][k] * koef;
            }
        }
    }

    my_remove_matrix(&temp);
    return det;
}

// Laplace expansion O(n!). Unacceptable for large matrices (8x8)
static double find_det(matrix_t *M, int *status) {
  double result = 0.0;

  if (M->rows == 0) 
      return 1.0;
  else if (M->rows == 1)
    return M->matrix[0][0];

  else if (M->rows == 2)
    return (M->matrix[0][0] * M->matrix[1][1] -
            M->matrix[0][1] * M->matrix[1][0]);

  else
      for (int j = 0; j < M->columns; ++j) {
        matrix_t minor_M = {0};
        *status = create_minor_matrix(M, &minor_M, 0, j);
        const double sign = j & 1 ? -1.0 : 1.0;
        result +=
            M->matrix[0][j] * sign * find_det(&minor_M, status);
        my_remove_matrix(&minor_M);
      }

  return result;
}

int my_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK)
    return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  int status = OK;
  status = my_create_matrix(A->rows, A->columns, result);

  if (status == OK) {
    switch (A->rows) {
      case 1:
        result->matrix[0][0] = 1.0;
        break;

      case 2:
        for (int i = 0; i < A->rows; ++i)
          for (int j = 0; j < A->columns; ++j) {
	    const double sign = (i + j) & 1 ? -1.0 : 1.0;
            result->matrix[i][j] = sign * A->matrix[i ^ 1][j ^ 1];
	  }
        break;

      default:
        for (int i = 0; i < A->rows; ++i)
          for (int j = 0; j < A->columns; ++j) {
            matrix_t temp = {0};
            status = create_minor_matrix(A, &temp, i, j);
	    const double sign = (i + j) & 1 ? -1.0 : 1.0;
            result->matrix[i][j] = sign * find_det(&temp, &status);
            my_remove_matrix(&temp);
          }
        break;
    }
  }
  return status;
}

int my_determinant(matrix_t *A, double *result) {
  if (!A || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK)
    return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;
  int status = OK;

  *result = find_det(A, &status);
  // *result = find_det_gauss(A, &status);

  return status;
}

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!A || !result)
    return INCORRECT_MATRIX;
  else if (ROW_COL_MORE_THAN_ZERO(A->rows, A->columns) != OK)
    return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  matrix_t comp = {0};
  int status = my_calc_complements(A, &comp);

  if (status == OK) {
    /* calc determinant from complements matrix */
    double det = 0.0;
    for (int j = 0; j < A->columns; ++j)
      det += A->matrix[0][j] * comp.matrix[0][j];

    if (det != 0) {
      matrix_t t = {0};
      status = my_transpose(&comp, &t);

      if (status == OK) status = my_mult_number(&t, 1 / det, result);
      my_remove_matrix(&t), my_remove_matrix(&comp);

    } else {
      my_remove_matrix(&comp);
      status = CALCULATION_ERROR;
    }
  }
  return status;
}
