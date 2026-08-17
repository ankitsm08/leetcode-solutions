#include <array>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_N = 500;
  static inline array<int, MAX_N * MAX_N> DP;
  static inline array<int, MAX_N + 1> pref;
  static inline int n = 0;

  static inline auto dp = [](int l, int r) -> int & { return DP[l * n + r]; };

public:
  static int score(int l, int r) {
    if (dp(l, r) != -1)
      return dp(l, r);

    int ans = 0;
    for (int m = l; m < r; m++) {
      const int left_sum = pref[m + 1] - pref[l];
      const int right_sum = pref[r + 1] - pref[m + 1];

      if (left_sum <= right_sum)
        ans = max(ans, left_sum + score(l, m));
      if (left_sum >= right_sum)
        ans = max(ans, right_sum + score(m + 1, r));

      if (2 * min(left_sum, right_sum) <= ans)
        break;
    }

    return dp(l, r) = ans;
  }

  static int stoneGameV(vector<int> &stoneValue) {
    n = static_cast<int>(stoneValue.size());
    fill(DP.begin(), DP.begin() + n * n, -1);

    partial_sum(stoneValue.begin(), stoneValue.end(), pref.begin() + 1);

    return score(0, n - 1);
  }
};
