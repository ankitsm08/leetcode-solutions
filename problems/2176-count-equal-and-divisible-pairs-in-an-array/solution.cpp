#include <vector>

using namespace std;

class Solution {
public:
  int countPairs(vector<int> &nums, int k) {
    int count = 0;

    for (size_t j = 1; j < nums.size(); j++) {
      for (size_t i = 0; i < j; i++) {
        if (nums[i] == nums[j] && static_cast<int>(i * j) % k == 0)
          count++;
      }
    }

    return count;
  }
};
