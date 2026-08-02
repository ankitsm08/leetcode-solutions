#include <vector>

using namespace std;

class Solution {
public:
  int countRatioSubarrays(vector<int> &nums, int a, int b) {
    const int n = static_cast<int>(nums.size());

    int valids = 0;
    for (int i = 0; i < n; i++) {
      int evens = 0, odds = 0;
      for (int j = i; j < n; j++) {
        evens += nums[j] % 2 == 0;
        odds += nums[j] % 2 == 1;
        valids += (evens * b <= a * odds);
      }
    }

    return valids;
  }
};
