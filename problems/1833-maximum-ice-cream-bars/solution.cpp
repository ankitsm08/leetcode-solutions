#include <algorithm>
#include <array>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  // INFO: Greedy Counting
  //
  int maxIceCream(vector<int> &costs, int coins) {
    constexpr int MAX_VALUE = 100000;

    // in static storage not stack
    static array<int, MAX_VALUE + 1> freq;
    fill(begin(freq), end(freq), 0);

    for (const int cost : costs) {
      freq[cost]++;
    }

    int count = 0;
    for (int price = 1; price <= MAX_VALUE; price++) {
      if (freq[price] == 0)
        continue;
      if (coins < price)
        break;

      const int can_buy = min(freq[price], coins / price);
      coins -= can_buy * price;
      count += can_buy;
    }

    return count;
  }

  // INFO: Sort Solution
  //
  // int maxIceCream(vector<int> &costs, int coins) {
  //   sort(costs.begin(), costs.end());
  //   int count = 0;
  //   for (const int cost : costs) {
  //     if (cost > coins)
  //       break;
  //     coins -= cost;
  //     count++;
  //   }
  //   return count;
  // }
};
