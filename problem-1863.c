int subsetXORSum(int *nums, int numsSize) {
  int or_all = 0;
  for (int i = 0; i < numsSize; i++) {
    or_all |= nums[i];
  }

  return or_all * (1 << (numsSize - 1));
}
