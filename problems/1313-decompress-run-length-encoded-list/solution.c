#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decompressRLElist(int *nums, int numsSize, int *returnSize) {
  int total_nums = 0;
  for (int i = 0; i < numsSize; i += 2) {
    total_nums += nums[i];
  }

  int *decomp = malloc(total_nums * sizeof(int));
  *returnSize = total_nums;

  int idx = 0;
  for (int i = 0; i < numsSize; i += 2) {
    for (int j = 0; j < nums[i]; j++) {
      decomp[idx++] = nums[i + 1];
    }
  }

  return decomp;
}
