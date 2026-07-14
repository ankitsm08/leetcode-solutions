int findGCD(int *nums, int numsSize) {
  int mn = nums[0], mx = nums[0];
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] < mn)
      mn = nums[i];
    if (nums[i] > mx)
      mx = nums[i];
  }

  while (mn != 0) {
    const int r = mx % mn;
    mx = mn;
    mn = r;
  }
  return mx;
}
