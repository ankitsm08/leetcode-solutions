#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    nth_element(nums.begin(), nums.begin() + 2, nums.end(), greater<>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};
