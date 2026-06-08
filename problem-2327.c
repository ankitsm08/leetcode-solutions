#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize,
                   int **returnColumnSizes) {
  const int size = gridSize - 2;
  *returnSize = size;

  int **matrix = (int **)malloc(size * sizeof(int *));
  *returnColumnSizes = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    matrix[i] = (int *)malloc(size * sizeof(int));
    (*returnColumnSizes)[i] = size;

    for (int j = 0; j < size; j++) {
      int max = grid[i][j];

      for (int p = i; p < i + 3; p++) {
        for (int q = j; q < j + 3; q++) {
          if (grid[p][q] > max) {
            max = grid[p][q];
          }
        }
      }

      matrix[i][j] = max;
    }
  }

  return matrix;
}
