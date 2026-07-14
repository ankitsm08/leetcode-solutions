#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    const auto [mn, mx] = minmax_element(nums.begin(), nums.end());
    return gcd(*mn, *mx);
  }
};
