#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int total_xor = 0, all_zero = 0;
    for (int num : nums) {
      total_xor ^= num;
      all_zero |= num;
    }

    if (all_zero == 0)
      return 0;

    return static_cast<int>(nums.size()) - !total_xor;
  }
};
