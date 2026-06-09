#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *concatWithReverse(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(numsSize * 2 * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    ans[i] = nums[i];
  }
  for (int i = 0; i < numsSize; i++) {
    ans[i + numsSize] = nums[numsSize - i];
  }
  return ans;
}
