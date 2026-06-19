#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int maxAltitude = 0, altitude = 0;
    for (const int altChange : gain) {
      maxAltitude = max(maxAltitude, (altitude += altChange));
    }
    return maxAltitude;
  }
};
