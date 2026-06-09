#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDegrees(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize) {
  int *ans = (int *)malloc(matrixSize * sizeof(int));
  for (size_t i = 0; i < matrixSize; i++) {
    ans[i] = 0;
    for (size_t j = 0; j < matrixSize; j++) {
      ans[i] += matrix[i][j];
    }
  }
  *returnSize = matrixSize;
  return ans;
}
