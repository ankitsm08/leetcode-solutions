class Solution {
public:
  int maxProduct(int n) {
    int max1 = 0, max2 = 0;
    for (int x = n; x > 0; x /= 10) {
      const int digit = x % 10;
      if (digit > max1) {
        max2 = max1;
        max1 = digit;
      } else if (digit > max2) {
        max2 = digit;
      }
    }
    return max1 * max2;
  }
};
