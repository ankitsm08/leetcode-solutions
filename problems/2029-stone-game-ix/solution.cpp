#include <array>
#include <cstdlib>
#include <vector>

using namespace std;
class Solution {
public:
  bool stoneGameIX(const vector<int> &stones) {
    array<int, 3> remFreq = {0, 0, 0};

    for (const int stone : stones)
      remFreq[stone % 3]++;

    if (remFreq[0] % 2 == 0)
      return remFreq[1] >= 1 && remFreq[2] >= 1;

    return abs(remFreq[1] - remFreq[2]) >= 3;
  }
};
