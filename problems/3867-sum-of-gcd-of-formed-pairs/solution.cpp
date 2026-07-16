#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  static inline vector<int> prefixGCD;

public:
  long long gcdSum(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    prefixGCD.resize(n);

    int mx = nums[0];
    prefixGCD[0] = mx;
    for (int i = 1; i < n; i++) {
      if (nums[i] > mx)
        mx = nums[i];
      prefixGCD[i] = gcd(mx, nums[i]);
    }

    sort(prefixGCD.begin(), prefixGCD.end());

    long long sum = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
      sum += gcd(prefixGCD[i], prefixGCD[j]);

    return sum;
  }
};
