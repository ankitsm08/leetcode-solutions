#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *transformArray(int *nums, int numsSize, int *returnSize) {
  int evens = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] % 2 == 0)
      evens++;
  }
  int *ans = malloc(numsSize * sizeof(int));
  for (int i = 0; i < evens; i++) {
    ans[i] = 0;
  }
  for (int i = evens; i < numsSize; i++) {
    ans[i] = 1;
  }
  *returnSize = numsSize;
  return ans;
}
