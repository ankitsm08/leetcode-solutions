#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    array<vector<int>, 2> arr;
    arr[0].reserve(nums.size());
    arr[1].reserve(nums.size() - 1);
    arr[0].push_back(nums[0]);
    arr[1].push_back(nums[1]);

    for (size_t i = 2; i < nums.size(); i++)
      arr[arr[0].back() <= arr[1].back()].push_back(nums[i]);

    arr[0].insert(arr[0].end(), arr[1].begin(), arr[1].end());

    return arr[0];
  }
};
