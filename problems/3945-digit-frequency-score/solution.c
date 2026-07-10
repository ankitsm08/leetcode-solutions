int digitFrequencyScore(int n) {
  int sum = 0;
  for (int copy = n; copy > 0; copy /= 10)
    sum += copy % 10;
  return sum;
}
