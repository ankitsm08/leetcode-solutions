inline int som(int n, int m) { return n >= m ? m * ((n / m) * (n / m + 1)) / 2 : 0; }

int sumOfMultiples(int n) {
  return som(n, 3) + som(n, 5) + som(n, 7) - som(n, 3 * 5) - som(n, 5 * 7) - som(n, 3 * 7)
         + som(n, 3 * 5 * 7);
}
