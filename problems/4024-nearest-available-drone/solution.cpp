#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int nearestDrone(vector<vector<int>> &drones, vector<int> &target) {
    const int n = static_cast<int>(drones.size());
    int minDist = numeric_limits<int>::max(), idx = -1;

    for (int i = 0; i < n; i++) {
      const int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
      if (distance <= drones[i][2] && distance < minDist) {
        minDist = distance;
        idx = i;
      }
    }

    return idx;
  }
};
