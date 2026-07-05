#include <algorithm>
#include <array>
#include <cctype>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MOD = static_cast<int>(1e9) + 7;

public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    const int n = static_cast<int>(board.size());

    auto getVal = [](char ch) -> int {
      if (ch == 'X')
        return -1;
      return isdigit(ch) ? ch - '0' : 0;
    };

    vector<pair<int, int>> prev(n, {-1, 0});
    vector<pair<int, int>> curr(n, {-1, 0});

    curr[n - 1] = {0, 1};

    array<int, 3> dr = {0, 1, 1};
    array<int, 3> dc = {1, 0, 1};

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int val = getVal(board[i][j]);
        if (val == -1)
          continue;

        auto &[currBestSum, currWays] = curr[j];

        for (int k = 0; k < 3; k++) {
          int row = i + dr[k], col = j + dc[k];
          if (row >= n || col >= n)
            continue;

          auto &[bestSum, ways] = row == i ? curr[col] : prev[col];
          if (bestSum == -1)
            continue;

          if (bestSum > currBestSum) {
            currBestSum = bestSum;
            currWays = ways;
          } else if (bestSum == currBestSum) {
            if ((currWays += ways) >= MOD)
              currWays -= MOD;
          }
        }

        if (currBestSum != -1)
          currBestSum += val;
      }

      swap(prev, curr);
      fill(curr.begin(), curr.end(), pair<int, int>{-1, 0});
    }

    auto &[bestSum, ways] = prev[0];
    if (ways > 0)
      return {bestSum, ways};
    return {0, 0};
  }
};
