#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    const auto [numMin, numMax] = minmax_element(nums.begin(), nums.end());
    return static_cast<long long>(*numMax - *numMin) * k;
  }
};
