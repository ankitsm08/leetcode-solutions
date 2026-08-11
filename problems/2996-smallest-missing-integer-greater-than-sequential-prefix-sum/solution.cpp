#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
  int missingInteger(vector<int> &nums) {
    constexpr int MAX_NUM = 50;
    const int n = static_cast<int>(nums.size());

    int i = 0;
    int pref = nums[0];
    for (i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1] + 1)
        pref += nums[i];
      else {
        if (pref > MAX_NUM)
          return pref;
        break;
      }
    }

    bitset<MAX_NUM + 2> seen;

    for (int j = i - 1; j < n; j++)
      seen.set(nums[j]);

    for (int num = pref; num <= MAX_NUM + 1; num++) {
      if (!seen.test(num))
        return num;
    }

    return pref;
  }
};
