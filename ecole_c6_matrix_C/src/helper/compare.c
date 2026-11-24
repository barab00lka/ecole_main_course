#include "../my_matrix.h"

static int compare_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  for (int i = 0; i < A->rows && status == SUCCESS; ++i)
    for (int j = 0; j < A->columns && status == SUCCESS; ++j)
      if ((fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)) status = FAILURE;

  return status;
}

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;
  int status = SUCCESS;
  status = compare_matrix(A, B);
  return status;
}
