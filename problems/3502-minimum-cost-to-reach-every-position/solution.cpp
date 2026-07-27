#include <vector>

using namespace std;

class Solution {
public:
  vector<int> minCosts(vector<int> &cost) {
    int mn = cost[0];
    for (int &i : cost) {
      mn = min(mn, i);
      i = mn;
    }
    return cost;
  }
};
