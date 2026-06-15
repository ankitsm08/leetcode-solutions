#include <vector>

using namespace std;

class Solution {
public:
  vector<int> minBitwiseArray(vector<int> &nums) {
    vector<int> ans(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 2) {
        ans[i] = -1;
        continue;
      }
      int pos = 1;
      while (((1 << pos) | nums[i]) == nums[i])
        pos++;
      int x = nums[i] - (1 << (pos - 1));
      ans[i] = x;
    }

    return ans;
  }
};
