int digitFrequencyScore(int n) {
  int prev = 0, count = 1, score = 0;
  while (n > 0) {
    int digit = n % 10;
    if (digit == prev) {
      count++;
    } else {
      score += prev * count;
      count = 1;
    }
    prev = digit;
    n /= 10;
  }
  score += prev * count;
  return score;
}
