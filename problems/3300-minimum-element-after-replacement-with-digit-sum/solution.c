#include <limits.h>

int sumOfDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int minElement(int *nums, int numsSize) {
  int minSum = INT_MAX;

  for (int i = 0; i < numsSize; i++) {
    int sum = sumOfDigits(nums[i]);
    if (sum < minSum)
      minSum = sum;
  }

  return minSum;
}
