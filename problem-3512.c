#include <stdlib.h>

int minOperations(int *nums, int numsSize, int k) {
  int sum = 0;
  for (size_t i = 0; i < numsSize; i++) {
    sum += nums[i];
  }
  return sum % k;
}
