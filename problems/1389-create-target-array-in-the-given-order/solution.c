#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize) {
  int *target = malloc(numsSize * sizeof(int));
  *returnSize = numsSize;
  int size = 0;

  for (int i = 0; i < numsSize; i++) {
    for (int j = size; j > index[i]; j--) {
      target[j] = target[j - 1];
    }

    target[index[i]] = nums[i];
    size++;
  }

  return target;
}
