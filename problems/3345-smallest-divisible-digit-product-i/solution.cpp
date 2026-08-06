class Solution {
public:
  int digitProduct(int num) {
    int res = num % 10;
    while (num /= 10)
      res *= num % 10;
    return res;
  }

  int smallestNumber(int n, int t) {
    while (digitProduct(n) % t != 0)
      n++;
    return n;
  }
};
