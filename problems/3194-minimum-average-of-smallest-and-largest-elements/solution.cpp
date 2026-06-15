#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  double minimumAverage(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    double min_avg = INT_MAX;
    for (int i = 0, j = nums.size() - 1; i < (nums.size() + 1) / 2; i++, j--) {
      min_avg = min(min_avg, (double)(nums[i] + nums[j]) / 2.0);
    }

    return min_avg;
  }
};
