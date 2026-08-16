#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minPenalty(int period, vector<int> &lights, vector<int> &arrivalTime) {
    int minPenalty = 0;
    int maxLight = ranges::max(lights);

    for (int time : arrivalTime) {
      const int mod = time % period;
      if (mod >= maxLight)
        minPenalty = max(minPenalty, period - mod);
    }

    return minPenalty;
  }
};
