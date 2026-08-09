#include <math.h>
#include <stdlib.h>

#define EPS 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum result_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

#define ROW_COL_MORE_THAN_ZERO(rows, cols) \
  ((rows > 0 && cols > 0) ? OK : INCORRECT_MATRIX)

int my_create_matrix(int rows, int columns, matrix_t *result);
int my_copy_matrix_fast(const matrix_t *src, matrix_t *dst);
void my_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0
int my_eq_matrix(matrix_t *A, matrix_t *B);

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_mult_number(matrix_t *A, double number, matrix_t *result);

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_transpose(matrix_t *A, matrix_t *result);

int my_calc_complements(matrix_t *A, matrix_t *result);

int my_determinant(matrix_t *A, double *result);

int my_inverse_matrix(matrix_t *A, matrix_t *result);
