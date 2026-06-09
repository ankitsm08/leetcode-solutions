int minBitFlips(int start, int goal) {
  int flips = 0;
  while (start != goal) {
    flips += start % 2 != goal % 2;
    start >>= 1;
    goal >>= 1;
  }
  return flips;
}
