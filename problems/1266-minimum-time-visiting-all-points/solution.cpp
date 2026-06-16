#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int x = points[0][0], y = points[0][1];

    int total_time = 0;
    for (size_t i = 1; i < points.size(); i++) {
      const int next_x = points[i][0], next_y = points[i][1];
      const int dist_x = abs(next_x - x), dist_y = abs(next_y - y);
      total_time += max(dist_x, dist_y);
      x = next_x, y = next_y;
    }

    return total_time;
  }
};
