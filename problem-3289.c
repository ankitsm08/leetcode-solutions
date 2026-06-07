#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getSneakyNumbers(int *nums, int numsSize, int *returnSize) {
  int *arr = malloc(2 * sizeof(int));
  *returnSize = 2;

  int idx = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] == nums[j]) {
        arr[idx++] = nums[i];
        if (idx == 2)
          return arr;
      }
    }
  }

  return arr;
}
