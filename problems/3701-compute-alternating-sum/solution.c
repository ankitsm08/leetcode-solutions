int alternatingSum(int *nums, int numsSize) {
  int alt_sum = 0;
  for (int i = 0; i < numsSize; i++) {
    alt_sum += i % 2 == 0 ? nums[i] : -nums[i];
  }
  return alt_sum;
}
