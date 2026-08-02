#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  using ll = long long;

public:
  ll maxPairStrength(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());

    sort(nums.begin(), nums.end(), greater<>());

    ll maxStrength = 0;
    for (int i = 0; i < n - 1; i++) {
      ll maxx = static_cast<ll>(nums[i]) * nums[i + 1];
      if (maxx <= maxStrength)
        break;

      for (int j = i + 1; j < n; j++) {
        maxx = static_cast<ll>(nums[i]) * nums[j];
        if (maxx <= maxStrength)
          break;
        const ll gcd_i_j = gcd(nums[i], nums[j]);
        maxStrength = max(maxStrength, maxx / (gcd_i_j * gcd_i_j));
      }
    }

    return maxStrength;
  }
};
