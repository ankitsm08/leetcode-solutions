#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<vector<int>> &mat) {
    const int m = static_cast<int>(mat.size());
    const int n = static_cast<int>(mat[0].size());

    // largest square ending at (i, j)
    vector<int> DP(m * n, 0);
    auto dp = [&](int i, int j) -> int & { return DP[i * n + j]; };

    int maxSide = 0;

    for (int i = 0; i < m; i++) {
      dp(i, 0) = mat[i][0];
      maxSide = max(maxSide, dp(i, 0));
    }
    for (int j = 0; j < n; j++) {
      dp(0, j) = mat[0][j];
      maxSide = max(maxSide, dp(0, j));
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (mat[i][j] == 1)
          dp(i, j) = 1 + min({dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1)});

        maxSide = max(maxSide, dp(i, j));
      }
    }

    auto possibleSubmatrix = [&](int k) -> bool {
      int rMin = m, cMin = n, rMax = -1, cMax = -1;

      for (int i = k - 1; i < m; i++) {
        for (int j = k - 1; j < n; j++) {
          if (dp(i, j) < k)
            continue;

          const int r = i - k + 1;
          const int c = j - k + 1;

          // no vertical overlap
          if (rMax >= 0 && r - rMin >= k)
            return true;

          if (rMax >= 0 && rMax - r >= k)
            return true;

          // no horizontal overlap
          if (cMax >= 0 && c - cMin >= k)
            return true;

          if (cMax >= 0 && cMax - c >= k)
            return true;

          rMin = min(rMin, r);
          rMax = max(rMax, r);
          cMin = min(cMin, c);
          cMax = max(cMax, c);
        }
      }

      return false;
    };

    // binary search over answer
    int high = maxSide;
    int low = 1;
    int best = 0;

    while (low <= high) {
      int k = high - (high - low) / 2;

      if (possibleSubmatrix(k)) {
        best = k;
        low = k + 1;
      } else
        high = k - 1;
    }

    return best * best;
  }
};
