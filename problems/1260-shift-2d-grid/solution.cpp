#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    const int total = m * n;

    if ((k %= total) == 0)
      return grid;

    auto reverse1d = [&](int i, int j) {
      while (i < j) {
        swap(grid[i / n][i % n], grid[j / n][j % n]);
        i++, j--;
      }
    };

    reverse1d(0, total - 1);
    reverse1d(0, k - 1);
    reverse1d(k, total - 1);

    return grid;
  }
};
