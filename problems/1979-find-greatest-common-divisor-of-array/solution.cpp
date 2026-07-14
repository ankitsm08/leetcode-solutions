#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    // INFO: Idiomatic C++
    //
    // const auto [mn, mx] = minmax_element(nums.begin(), nums.end());
    // return gcd(*mn, *mx);

    // INFO: Regular Solution
    int mn = nums[0], mx = nums[0];
    for (int num : nums) {
      if (num < mn)
        mn = num;
      if (num > mx)
        mx = num;
    }

    while (mn != 0) {
      const int r = mx % mn;
      mx = mn;
      mn = r;
    }
    return mx;
  }
};
