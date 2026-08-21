#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
  using ll = long long;

  static inline vector<int> effectiveCoins;
  static inline bool init = []() {
    constexpr int MAX_COINS = 15;
    effectiveCoins.reserve(MAX_COINS);
    return true;
  }();

public:
  long long findKthSmallest(vector<int> &coins, int k) {
    ranges::sort(coins);

    effectiveCoins.clear();
    for (auto &coin : coins) {
      if (ranges::none_of(effectiveCoins, [&](int x) { return !(coin % x); }))
        effectiveCoins.push_back(coin);
    }

    const int n = static_cast<int>(effectiveCoins.size());

    auto formableUpTo = [&](ll amount) {
      ll total = 0;

      for (int subsetSize = 1; subsetSize <= n; subsetSize++) {
        int subsetMask = (1 << subsetSize) - 1;

        while (subsetMask < (1 << n)) {
          ll lcmVal = 1;
          for (int idx = 0; idx < n; idx++)
            if ((subsetMask >> idx) & 1)
              lcmVal = lcm(lcmVal, effectiveCoins[idx]);

          const int sign = ((subsetSize & 1) << 1) - 1;
          total += (amount / lcmVal) * sign;

          const int rightmostBit = subsetMask & -subsetMask;
          const int nextMask = subsetMask + rightmostBit;
          subsetMask = (((nextMask ^ subsetMask) >> 2) / rightmostBit) | nextMask;
        }
      }

      return total;
    };

    const ll low = k;
    const ll high = 1LL * effectiveCoins[0] * k;

    return *ranges::lower_bound(views::iota(low, high + 1), true, {},
                                [&](ll amount) { return formableUpTo(amount) >= k; });
  }
};
