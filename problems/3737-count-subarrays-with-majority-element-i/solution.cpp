#include <vector>

using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    const size_t n = nums.size();

    size_t balance = n;
    vector<int> prefix(2 * n + 1, 0);
    prefix[balance] = 1;

    int query = 0, total = 0;

    for (const int x : nums) {
      if (x == target)
        query += prefix[balance++];
      else
        query -= prefix[--balance];

      prefix[balance]++;
      total += query;
    }

    return total;
  }
};
