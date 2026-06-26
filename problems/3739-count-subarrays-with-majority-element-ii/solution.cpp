#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    const size_t n = nums.size();

    vector<int> prefix(2 * n + 1, 0);
    size_t balance = n;
    prefix[n] = 1;

    long long total = 0, query = 0;

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
