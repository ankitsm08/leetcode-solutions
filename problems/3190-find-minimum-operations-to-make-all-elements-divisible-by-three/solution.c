int minimumOperations(int *nums, int numsSize) {
  int operations = 0;
  for (int i = 0; i < numsSize; i++) {
    operations += nums[i] % 3 != 0;
  }
  return operations;
}
