#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> ans;
    ans.reserve(nums.size());

    for (int num : nums) {
      for (char digit : to_string(num)) {
        ans.push_back(digit - '0');
      }
    }

    return ans;
  }
};
