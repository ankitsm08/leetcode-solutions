#include <vector>

using namespace std;

#define MIN_RANGE 0
#define MAX_RANGE 100

class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    int seen[MAX_RANGE - MIN_RANGE + 1] = {0};

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] - k >= MIN_RANGE)
        count += seen[nums[i] - k - MIN_RANGE];
      if (nums[i] + k <= MAX_RANGE)
        count += seen[nums[i] + k - MIN_RANGE];
      seen[nums[i] - MIN_RANGE]++;
    }

    return count;
  }
};
