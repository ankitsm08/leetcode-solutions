#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int earliestTime(vector<vector<int>> &tasks) {
    int min_time = INT_MAX;
    for (auto &task : tasks) {
      min_time = min(min_time, task[0] + task[1]);
    }
    return min_time;
  }
};
