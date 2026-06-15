#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    unordered_set<int> s(nums.begin(), nums.end());

    int count = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (s.count(nums[j] - diff) && s.count(nums[j] + diff))
        count++;
    }

    return count;
  }
};
