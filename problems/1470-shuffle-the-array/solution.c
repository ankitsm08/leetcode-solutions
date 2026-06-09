#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
  int *shuffled = malloc(numsSize * sizeof(int));
  *returnSize = numsSize;

  for (int i = 0; i < numsSize; i++) {
    if (i % 2 == 0) {
      shuffled[i] = nums[i / 2];
    } else {
      shuffled[i] = nums[n + i / 2];
    }
  }

  return shuffled;
}
