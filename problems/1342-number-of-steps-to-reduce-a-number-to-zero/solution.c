int numberOfSteps(int num) {
  int steps = -(num != 0);
  while (num) {
    steps += (num & 1) + 1;
    num >>= 1;
  }
  return steps;
}
