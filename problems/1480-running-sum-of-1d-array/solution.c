#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *runningSum(int *nums, int numsSize, int *returnSize) {
  int *sum = malloc(numsSize * sizeof(int));
  *returnSize = numsSize;

  sum[0] = nums[0];
  for (int i = 1; i < numsSize; i++) {
    sum[i] = sum[i - 1] + nums[i];
  }

  return sum;
}
