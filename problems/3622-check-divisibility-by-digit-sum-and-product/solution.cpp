class Solution {
public:
  bool checkDivisibility(int n) {
    int sum = 0, prod = 1;
    for (int x = n; x > 0; x /= 10) {
      const int digit = x % 10;
      sum += digit;
      prod *= digit;
    }
    return n % (sum + prod) == 0;
  }
};
