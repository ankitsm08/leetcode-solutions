#include <array>

using namespace std;

class Solution {
  using ll = long long;

  struct Result {
    ll count;
    ll waivness;
  };

  static constexpr int MAX_DIGITS = 16;

  static inline array<int, MAX_DIGITS> digits;
  static inline int digitCount;

  static inline array<Result, (MAX_DIGITS + 1) * 11 * 11 * 2> dp;
  static inline const bool init = []() {
    dp.fill({-1, -1});
    return true;
  }();

  static Result &at(int rem, int prev2, int prev1, bool non_zero) {
    return dp[((rem * 11 + prev2) * 11 + prev1) * 2 + non_zero];
  }

public:
  Result solve(int rem, int prev2, int prev1, bool small, bool non_zero) {
    if (rem == 0)
      return {1, 0};
    if (small && at(rem, prev2, prev1, non_zero).count != -1)
      return at(rem, prev2, prev1, non_zero);

    const int limit = small ? 9 : digits[rem - 1];
    Result res = {0, 0};

    for (int currDigit = 0; currDigit <= limit; currDigit++) {
      bool new_small = small || currDigit < limit;
      bool new_non_zero = non_zero || currDigit != 0;
      int new_prev2 = prev2, new_prev1 = prev1;
      int wave_added = 0;

      if (new_non_zero) {
        wave_added =
            (prev2 != 10 && prev1 != 10)
            && ((prev2 > prev1 && prev1 < currDigit) || (prev2 < prev1 && prev1 > currDigit));
        new_prev2 = prev1;
        new_prev1 = currDigit;
      }

      Result next_res = solve(rem - 1, new_prev2, new_prev1, new_small, new_non_zero);
      res.count += next_res.count;
      res.waivness += next_res.waivness + next_res.count * wave_added;
    }

    if (small)
      at(rem, prev2, prev1, non_zero) = res;

    return res;
  }

  ll waviness(ll num) {
    if (num <= 100)
      return 0;

    digitCount = 0;
    for (ll x = num; x > 0; x /= 10)
      digits[digitCount++] = x % 10;

    return solve(digitCount, 10, 10, false, false).waivness;
  }

  inline ll totalWaviness(ll num1, ll num2) { return waviness(num2) - waviness(num1 - 1); }
};
