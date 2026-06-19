#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    stack<size_t> stack;

    for (size_t i = 0; i < prices.size(); i++) {
      while (!stack.empty() && prices[i] <= prices[stack.top()]) {
        prices[stack.top()] = prices[stack.top()] - prices[i];
        stack.pop();
      }
      stack.push(i);
    }

    return prices;
  }
};
