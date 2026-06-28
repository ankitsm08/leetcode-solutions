#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    const size_t n = arr.size();

    vector<int> count(n + 1, 0);
    for (const int num : arr) {
      count[min(num, static_cast<int>(n))]++;
    }

    int ans = 1;
    for (size_t num = 2; num <= n; num++) {
      ans = min(ans + count[num], static_cast<int>(num));
    }

    return ans;
  }
};
