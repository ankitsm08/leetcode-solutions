#include <array>
#include <vector>

using namespace std;

// INFO: Dynamic Programming
class Solution {
  static constexpr int MAX_N = 20;
  static inline array<int, MAX_N> dp;

public:
  bool predictTheWinner(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    if (n % 2 == 0)
      return true;

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = nums[i];
      for (int j = i + 1; j < n; j++)
        dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
    }

    return dp[n - 1] >= 0;
  }
};

// INFO: Recursive Solution
class SolutionRecursive {
  static constexpr int MAX_N = 20;
  static inline array<int, MAX_N * MAX_N> dp;

public:
  bool predictTheWinner(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    if (n % 2 == 0)
      return true;

    dp.fill(-1);
    auto maxDiff = [&](auto &&maxDiff, int i, int j) -> int {
      int &memo = dp[i * MAX_N + j];
      if (memo != -1)
        return memo;
      if (i == j)
        return memo = nums[i];

      return memo = max(nums[i] - maxDiff(maxDiff, i + 1, j), nums[j] - maxDiff(maxDiff, i, j - 1));
    };

    return maxDiff(maxDiff, 0, n - 1) >= 0;
  }
};
