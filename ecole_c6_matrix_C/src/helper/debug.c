#include <stdio.h>

#include "../my_matrix.h"

void populate_matrix(matrix_t *result) {
  double cnt = 0.0;
  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++) result->matrix[i][j] = ++cnt;
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
