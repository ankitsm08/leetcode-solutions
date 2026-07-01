#include <algorithm>
#include <array>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    const int n = static_cast<int>(grid.size());
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return 0;

    vector<int> Safeness(n * n, -1);
    auto safeness = [&](int i, int j) -> int & { return Safeness[i * n + j]; };

    using Point = pair<int, int>;
    queue<Point> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          safeness(i, j) = 0;
          q.emplace(i, j);
        }
      }
    }

    array<int, 4> dr = {0, 0, 1, -1};
    array<int, 4> dc = {1, -1, 0, 0};

    // multi-source bfs preprocessing
    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = row + dr[i], nc = col + dc[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
          continue;
        if (safeness(nr, nc) == -1) {
          safeness(nr, nc) = safeness(row, col) + 1;
          q.emplace(nr, nc);
        }
      }
    }

    // INFO: Dial's Algorithm
    //
    vector<bool> Visited(n * n, false);
    auto visited = [&](int i, int j) -> vector<bool>::reference { return Visited[i * n + j]; };

    vector<Point> curr, next;
    curr.emplace_back(0, 0);
    visited(0, 0) = true;

    int ans = min(safeness(0, 0), safeness(n - 1, n - 1));

    while (ans > 0 && !curr.empty()) {
      while (!curr.empty()) {
        auto [row, col] = curr.back();
        curr.pop_back();

        if (row == n - 1 && col == n - 1)
          return ans;

        for (int i = 0; i < 4; i++) {
          int nr = row + dr[i], nc = col + dc[i];
          if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited(nr, nc))
            continue;

          if (safeness(nr, nc) >= ans)
            curr.emplace_back(nr, nc);
          else
            next.emplace_back(nr, nc);

          visited(nr, nc) = true;
        }
      }

      swap(curr, next);
      ans--;
    }

    return ans;

    // INFO: Modified Dijkstra + Priority Queue
    //
    // using Cell = pair<int, Point>;
    // auto cmp = [](const Cell &c1, const Cell &c2) { return c1.first < c2.first; };
    // priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);
    // vector<int> MaxSafePath(n * n, -1);
    // auto max_safe_path = [&](int i, int j) -> int & { return MaxSafePath[i * n + j]; };
    //
    // pq.emplace(safeness(0, 0), Point{0, 0});
    // max_safe_path(0, 0) = safeness(0, 0);
    //
    // while (!pq.empty()) {
    //   auto [current_safeness, point] = pq.top();
    //   auto [row, col] = point;
    //   pq.pop();
    //
    //   if (row == n - 1 && col == n - 1)
    //     return current_safeness;
    //
    //   if (max_safe_path(row, col) > current_safeness)
    //     continue;
    //
    //   for (int i = 0; i < 4; i++) {
    //     int nr = row + dr[i], nc = col + dc[i];
    //     if (nr < 0 || nr >= n || nc < 0 || nc >= n)
    //       continue;
    //
    //     int new_safeness = min(current_safeness, safeness(nr, nc));
    //     if (new_safeness > max_safe_path(nr, nc)) {
    //       pq.emplace(new_safeness, Point{nr, nc});
    //       max_safe_path(nr, nc) = new_safeness;
    //     }
    //   }
    // }
    //
    // return 0;

    // INFO: Binary Search + BFS over Answer
    //
    // vector<bool> Visited(n * n, false);
    // auto visited = [&](int i, int j) -> vector<bool>::reference { return Visited[i * n + j]; };
    //
    // // binary search on answer
    // int max_dist = 0;
    // int low = 0, high = min(Safeness.front(), Safeness.back());
    // while (low <= high) {
    //   int mid = low + ((high - low) >> 1);
    //   bool pathPossible = false;
    //
    //   if (safeness(0, 0) < mid) {
    //     high = mid - 1;
    //     continue;
    //   }
    //
    //   // bfs check
    //   fill(Visited.begin(), Visited.end(), false);
    //   queue<Point> qq;
    //   qq.emplace(0, 0);
    //   visited(0, 0) = true;
    //   while (!qq.empty() && !pathPossible) {
    //     auto [row, col] = qq.front();
    //     qq.pop();
    //
    //     for (int i = 0; i < 4; i++) {
    //       int nr = row + dr[i], nc = col + dc[i];
    //       if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited(nr, nc))
    //         continue;
    //       if (nr == n - 1 && nc == n - 1) {
    //         pathPossible = true;
    //         break;
    //       }
    //       if (safeness(nr, nc) >= mid) {
    //         qq.emplace(nr, nc);
    //         visited(nr, nc) = true;
    //       }
    //     }
    //   }
    //
    //   if (pathPossible) {
    //     max_dist = mid;
    //     low = mid + 1;
    //   } else {
    //     high = mid - 1;
    //   }
    // }
    //
    // return max_dist;
  }
};
