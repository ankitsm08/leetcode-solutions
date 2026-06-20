#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &restrictions) {
    if (restrictions.size() <= 0)
      return n - 1;

    vector<pair<int, int>> R;
    R.reserve(restrictions.size() + 2);

    R.push_back({1, 0});
    for (const auto &r : restrictions) {
      R.push_back({r[0], r[1]});
    }

    sort(R.begin(), R.end());

    if (R.back().first != n)
      R.push_back({n, INT_MAX});

    const size_t k = R.size();

    for (size_t i = 1; i < k; i++) {
      const int dist = R[i].first - R[i - 1].first;
      R[i].second = min(R[i - 1].second + dist, R[i].second);
    }

    for (size_t i = k - 1; i-- > 0;) {
      const int dist = R[i + 1].first - R[i].first;
      R[i].second = min(R[i].second, R[i + 1].second + dist);
    }

    int max_height = 0;
    for (size_t i = 1; i < k; i++) {
      const int dist = R[i].first - R[i - 1].first;
      const int new_peak = (0LL + R[i - 1].second + R[i].second + dist) / 2;
      max_height = max(max_height, new_peak);
    }

    return max_height;
  }
};

int main() {
  Solution sol;
  {
    vector<vector<int>> restrictions = {{2, 1}, {4, 1}};
    cout << sol.maxBuilding(5, restrictions) << " -> " << 2 << endl;
  }
  {
    vector<vector<int>> restrictions = {};
    cout << sol.maxBuilding(6, restrictions) << " -> " << 5 << endl;
  }
  {
    vector<vector<int>> restrictions = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    cout << sol.maxBuilding(10, restrictions) << " -> " << 5 << endl;
  }
  return 0;
}
