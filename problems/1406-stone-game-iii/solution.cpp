#include <algorithm>
#include <array>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    const size_t n = stoneValue.size();

    array<int, 4> dp = {0, 0, 0, 0};
    for (size_t i = n; i-- > 0;) {
      int take = 0;
      int best = numeric_limits<int>::min();

      for (size_t k = 0; k < 3 && i + k < n; k++) {
        take += stoneValue[i + k];
        best = max(best, take - dp[(i + k + 1) & 3]);
      }

      dp[i & 3] = best;
    }

    return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
  }
};
