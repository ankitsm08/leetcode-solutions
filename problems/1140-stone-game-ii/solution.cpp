#include <array>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_PILES = 100;
  static inline array<int, MAX_PILES + 1> suffix{};
  static inline array<array<int, MAX_PILES + 1>, MAX_PILES + 1> dp{};

public:
  int stoneGameII(vector<int> &piles) {
    const int n = static_cast<int>(piles.size());

    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--)
      suffix[i] = suffix[i + 1] + piles[i];

    for (int i = 0; i <= n; i++) {
      dp[i].fill(0);
      dp[i][n] = suffix[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int M = n - 1; M >= 1; M--) {
        for (int X = 1; X <= 2 * M && i + X <= n; X++)
          dp[i][M] = max(dp[i][M], suffix[i] - dp[i + X][max(M, X)]);
      }
    }

    return dp[0][1];
  }
};
