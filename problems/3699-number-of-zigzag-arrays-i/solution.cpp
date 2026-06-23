#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    if (n == 1)
      return r - l + 1;

    const int64_t mod = static_cast<int64_t>(1e9) + 7;
    const size_t K = r - l + 1;

    // base case
    vector<int64_t> dp(K, 1);

    for (int i = 1; i < n; i++) {
      int64_t sum = 0, prev = 0;

      // alternate per element
      if (i & 1) {
        // prefix sum and state transition
        for (size_t j = 0; j < K; j++) {
          prev = dp[j];
          dp[j] = sum;
          sum += prev;
          if (sum >= mod)
            sum -= mod;
        }
      } else {
        for (size_t j = K; j-- > 0;) {
          prev = dp[j];
          dp[j] = sum;
          sum += prev;
          if (sum >= mod)
            sum -= mod;
        }
      }
    }

    int64_t total_valid = 0;
    for (size_t i = 0; i < K; i++) {
      total_valid += dp[i];
      if (total_valid >= mod)
        total_valid -= mod;
    }

    total_valid *= 2;
    if (total_valid >= mod)
      total_valid -= mod;

    return static_cast<int>(total_valid);
  }
};
