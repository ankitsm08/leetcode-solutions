#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    size_t rows = grid.size();
    size_t cols = grid[0].size();

    vector<int> dp(cols, 0);
    dp[0] = grid[0][0];

    for (size_t j = 1; j < cols; j++) {
      dp[j] = dp[j - 1] + grid[0][j];
    }

    for (size_t i = 1; i < rows; i++) {
      dp[0] += grid[i][0];
      for (size_t j = 1; j < cols; j++) {
        dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
      }
    }

    return dp.back();
  }
};
