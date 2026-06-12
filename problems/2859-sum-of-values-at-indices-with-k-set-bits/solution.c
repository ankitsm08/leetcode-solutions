int sumIndicesWithKSetBits(int *nums, int numsSize, int k) {
  int sum = 0;

  for (int i = 0; i < numsSize; i++) {
    int bits = 0;
    int idx = i;
    while (idx > 0) {
      bits += idx & 1;
      idx >>= 1;
    }
    if (bits == k)
      sum += nums[i];
  }

  return sum;
}
