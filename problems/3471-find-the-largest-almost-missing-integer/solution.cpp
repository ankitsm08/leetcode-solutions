#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
  constexpr static int MAX_NUM = 50;

public:
  int largestInteger(vector<int> &nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (k == n)
      return ranges::max(nums);

    array<uint8_t, MAX_NUM + 1> freq{};
    for (int num : nums)
      freq[num]++;

    int ans = -1;
    auto consider = [&](int p) {
      if (freq[nums[p]] == 1)
        ans = max(ans, nums[p]);
    };

    if (k == 1) {
      for (int p = 0; p < n; p++)
        consider(p);
    } else {
      consider(0);
      consider(n - 1);
    }

    return ans;
  }
};
