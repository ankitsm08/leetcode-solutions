#include <vector>

using namespace std;

class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    int sum_diff = 0;

    for (int num : nums) {
      while ((num /= 10) > 0) {
        sum_diff += 9 * num;
      }
    }

    return sum_diff;
  }
};
