#include <vector>

using namespace std;

class Solution {
public:
  // INFO: Dynamic Programming
  //
  // int uniquePaths(int m, int n) {
  //   const auto rows = static_cast<size_t>(m);
  //   const auto cols = static_cast<size_t>(n);
  //
  //   vector<int> dp(cols, 1);
  //
  //   for (size_t i = 1; i < rows; i++) {
  //     for (size_t j = 1; j < cols; j++) {
  //       dp[j] += dp[j - 1];
  //     }
  //   }
  //
  //   return dp.back();
  // }

  // INFO: Combinatorics
  //
  int uniquePaths(int m, int n) {
    long long ans = 1;

    const int k = min(m - 1, n - 1);
    for (int i = 1; i <= k; i++) {
      ans = ans * (m + n - 2 - k + i) / i;
    }

    return static_cast<int>(ans);
  }
};
