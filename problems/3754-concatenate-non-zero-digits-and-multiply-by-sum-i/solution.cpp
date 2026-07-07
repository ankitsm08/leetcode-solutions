class Solution {
public:
  long long sumAndMultiply(int n) {
    int sum = 0;
    int num = 0;
    long long mult = 1;

    while (n > 0) {
      const int digit = n % 10;
      sum += digit;
      if (digit != 0) {
        num += digit * mult;
        mult *= 10;
      }
      n /= 10;
    }
    return static_cast<long long>(num) * sum;
  }
};
