#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *separateDigits(int *nums, int numsSize, int *returnSize) {
  int count = 0;
  for (int i = numsSize - 1; i >= 0; i--) {
    int num = nums[i];
    while (num > 0) {
      count++;
      num /= 10;
    }
  }

  int *answer = malloc(count * sizeof(int));
  *returnSize = count;

  for (int i = numsSize - 1, j = count - 1; i >= 0; i--) {
    int num = nums[i];
    while (num > 0) {
      answer[j--] = num % 10;
      num /= 10;
    }
  }

  return answer;
}
