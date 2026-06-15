#include <vector>

using namespace std;

class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }

    int count = 0, sum_left = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      sum_left += nums[i];
      int sum_diff = 2 * sum_left - sum;
      if (sum_diff % 2 == 0)
        count++;
    }

    return count;
  }
};
