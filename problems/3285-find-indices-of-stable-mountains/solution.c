#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *stableMountains(int *height, int heightSize, int threshold, int *returnSize) {
  int count = 0;
  for (int i = 1; i < heightSize; i++) {
    if (height[i - 1] > threshold) {
      count++;
    }
  }

  int *stable = malloc(count * sizeof(int));
  *returnSize = count;
  int idx = 0;
  for (int i = 1; i < heightSize; i++) {
    if (height[i - 1] > threshold) {
      stable[idx++] = i;
    }
  }
  return stable;
}
