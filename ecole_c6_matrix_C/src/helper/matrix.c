#include "../my_matrix.h"
#include <string.h>

static int init_matrix(int rows, int columns, matrix_t *pM) {
  int status = OK;
  pM->matrix = (double **)calloc(rows * columns + rows * sizeof(double *), sizeof(double));
  if (!pM->matrix) status = INCORRECT_MATRIX;
  double *ptr = (double *)(pM->matrix + rows);
  for (int i = 0; i < rows; i++) pM->matrix[i] = ptr + columns * i;
  return status;
}

int my_create_matrix(int rows, int columns, matrix_t *result) {
  if (ROW_COL_MORE_THAN_ZERO(rows, columns) != OK)
    return INCORRECT_MATRIX;
  else if (!result)
    return INCORRECT_MATRIX;
  result->columns = columns, result->rows = rows;
  return init_matrix(rows, columns, result);
}

void my_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    free(A->matrix);
    A->matrix = NULL;
  }
}

int my_copy_matrix_fast(const matrix_t *src, matrix_t *dst) {
    if (!src || !dst || src == dst) return INCORRECT_MATRIX;

    dst->rows = src->rows;
    dst->columns = src->columns;

    size_t ptrs_size = dst->rows * sizeof(double*);
    size_t data_size = dst->rows * dst->columns * sizeof(double);
    dst->matrix = (double**)malloc(ptrs_size + data_size);
    if (!dst->matrix) return INCORRECT_MATRIX;

    double *data_area = (double*)(dst->matrix + dst->rows);
    for (int i = 0; i < dst->rows; ++i)
        dst->matrix[i] = data_area + dst->columns * i;

    double *src_data = (double*)(src->matrix + src->rows);
    memcpy(data_area, src_data, data_size);

    return OK;
}
