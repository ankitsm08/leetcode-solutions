#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> aggregateTimeSeries(vector<vector<int>> &series1,
                                          vector<vector<int>> &series2) {
    const int m = static_cast<int>(series1.size());
    const int n = static_cast<int>(series2.size());
    vector<vector<int>> aggr;
    aggr.reserve(m + n);

    int i = 0, j = 0;
    while (i < m && j < n) {
      const int t1 = series1[i][0], t2 = series2[j][0];
      const int v1 = series1[i][1], v2 = series2[j][1];
      if (t1 < t2) {
        aggr.push_back({t1, v1 + v2});
        i++;
      } else {
        aggr.push_back({t2, v1 + v2});
        j++;
        i += t1 == t2;
      }
    }

    while (i < m) {
      aggr.push_back(series1[i]);
      i++;
    }

    while (j < n) {
      aggr.push_back(series2[j]);
      j++;
    }

    return aggr;
  }
};
