class Solution {
public:
  int mySqrt(int x) {
    constexpr int INT_MAX_SQRT = 46340;

    int low = 0, high = INT_MAX_SQRT;

    while (low <= high) {
      const int mid = low + ((high - low) >> 1);
      const int sqr = mid * mid;

      if (sqr < x) {
        low = mid + 1;
      } else if (sqr > x) {
        high = mid - 1;
      } else {
        return mid;
      }
    }

    return high;
  }
};
