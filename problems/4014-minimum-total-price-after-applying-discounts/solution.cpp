#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  double minPrice(vector<int> &prices, vector<int> &discounts) {
    double final = 0.0;

    ranges::sort(prices, greater<>());
    ranges::sort(discounts, greater<>());

    const size_t n = min(prices.size(), discounts.size());

    for (size_t i = 0; i < n; i++)
      final += static_cast<double>(prices[i]) * (100.0 - discounts[i]) / 100.0;

    for (size_t i = n; i < prices.size(); i++)
      final += static_cast<double>(prices[i]);

    return final;
  }
};
