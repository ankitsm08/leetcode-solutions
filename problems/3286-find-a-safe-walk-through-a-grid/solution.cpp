#include <array>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    array<int, 4> dr = {0, 1, 0, -1};
    array<int, 4> dc = {1, 0, -1, 0};

    vector<bool> Visited(m * n, false);
    auto visited = [&](int i, int j) -> vector<bool>::reference { return Visited[i * n + j]; };

    using Point = pair<int, int>;

    vector<Point> curr, next;
    curr.emplace_back(0, 0);
    visited(0, 0) = true;
    health -= grid[0][0];

    while (health > 0) {
      while (!curr.empty()) {
        auto [row, col] = curr.back();
        curr.pop_back();

        if (row == m - 1 && col == n - 1)
          return true;

        for (int i = 0; i < 4; i++) {
          int nr = row + dr[i], nc = col + dc[i];
          if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited(nr, nc))
            continue;

          if (grid[nr][nc] == 0)
            curr.emplace_back(nr, nc);
          else
            next.emplace_back(nr, nc);

          visited(nr, nc) = true;
        }
      }

      swap(curr, next);
      health--;
    }

    return false;
  }
};
