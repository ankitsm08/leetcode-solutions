#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    const int n = static_cast<int>(grid.size());

    vector<bool> freq(n * n + 1, false);
    int a = 0, b = 0;

    for (auto &row : grid) {
      for (int val : row) {
        if (freq[val])
          a = val;
        freq[val] = true;
      }
    }

    for (int i = 1; i <= n * n; i++) {
      if (freq[i] == 0) {
        b = i;
        break;
      }
    }

    return {a, b};
  }
};
