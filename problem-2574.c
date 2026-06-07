#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *leftRightDifference(int *nums, int numsSize, int *returnSize) {
  int *answer = malloc(numsSize * sizeof(int));
  *returnSize = numsSize;

  int leftSum[numsSize];
  leftSum[0] = 0;
  int rightSum[numsSize];
  rightSum[numsSize - 1] = 0;

  for (int i = 1; i < numsSize; i++) {
    leftSum[i] = leftSum[i - 1] + nums[i - 1];
  }
  for (int i = numsSize - 2; i >= 0; i--) {
    rightSum[i] = rightSum[i + 1] + nums[i + 1];
  }

  for (int i = 0; i < numsSize; i++) {
    answer[i] = abs(leftSum[i] - rightSum[i]);
  }

  return answer;
}
