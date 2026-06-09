int countPairs(int *nums, int numsSize, int target) {
  int pairs = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      pairs += nums[i] + nums[j] < target;
    }
  }
  return pairs;
}
