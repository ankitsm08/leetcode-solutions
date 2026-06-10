int hammingDistance(int start, int goal) {
  int dist = 0;
  while (start != goal) {
    dist += start % 2 != goal % 2;
    start >>= 1;
    goal >>= 1;
  }
  return dist;
}
