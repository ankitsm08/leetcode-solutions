#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  using ll = long long;

  static constexpr int MAX_NUM = static_cast<int>(5 * 1e4);

  static inline array<int, MAX_NUM + 1> numCount{};
  static inline array<ll, MAX_NUM + 1> gcdArr{};

public:
  vector<int> gcdValues(vector<int> &nums, vector<ll> &queries) {
    int mx = 0;
    for (int num : nums) {
      numCount[num]++;
      if (mx < num)
        mx = num;
    }

    for (int i = mx; i > 0; i--) {
      gcdArr[i] = 0;

      ll count = 0, extra = 0;
      for (int j = i; j <= mx; j += i)
        count += numCount[j], extra += gcdArr[j];

      gcdArr[i] = (count * (count - 1) >> 1) - extra;
    }

    fill(numCount.begin(), numCount.begin() + mx + 1, 0);
    partial_sum(gcdArr.begin(), gcdArr.begin() + mx + 1, gcdArr.begin());

    vector<int> result;
    result.reserve(queries.size());

    for (ll query : queries) {
      auto it = upper_bound(gcdArr.begin(), gcdArr.begin() + mx + 1, query);
      result.push_back(static_cast<int>(it - gcdArr.begin()));
    }

    return result;
  }
};
