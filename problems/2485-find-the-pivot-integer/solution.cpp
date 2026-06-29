#include <cmath>

class Solution {
public:
  int pivotInteger(int n) {
    const int sq = (n * (n + 1)) >> 1;
    const int root = static_cast<int>(std::sqrt(sq));
    if (root * root != sq)
      return -1;
    return root;
  }
};
