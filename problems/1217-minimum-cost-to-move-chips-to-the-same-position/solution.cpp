#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    const int n = static_cast<int>(position.size());
    int odd = 0;
    for (int x : position)
      odd += x % 2;
    return min(odd, n - odd);
  }
};
