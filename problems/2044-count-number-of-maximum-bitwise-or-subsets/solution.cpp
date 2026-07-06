#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  int maxOR;
  int n;

  int dfs(const vector<int> &nums, int idx, int cur) {
    if (cur == maxOR)
      return 1 << (n - idx);

    if (idx == n)
      return 0;

    return dfs(nums, idx + 1, cur | nums[idx]) + dfs(nums, idx + 1, cur);
  }

public:
  int countMaxOrSubsets(vector<int> &nums) {
    n = static_cast<int>(nums.size());
    maxOR = 0;
    for (int x : nums)
      maxOR |= x;

    sort(nums.begin(), nums.end(), greater<>());

    return dfs(nums, 0, 0);
  }
};
