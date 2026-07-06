#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });

    int right = -1, result = 0;
    for (auto &pair : intervals) {
      if (pair[1] > right) {
        result++;
        right = pair[1];
      }
    }

    return result;
  }
};
