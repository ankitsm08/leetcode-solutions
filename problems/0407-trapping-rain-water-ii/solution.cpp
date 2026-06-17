#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    const size_t m = heightMap.size();
    const size_t n = heightMap[0].size();

    using wall = pair<int, size_t>;
    const auto cmp = [](const wall &w1, const wall &w2) { return w1.first > w2.first; };
    priority_queue<wall, vector<wall>, decltype(cmp)> pq(cmp);
    int water = 0;

    vector<char> visited(m * n, 0);

    const auto get_idx = [n](const size_t r, const size_t c) { return r * n + c; };

    for (size_t j = 0; j < n; j++) {
      pq.push(wall({heightMap[0][j], get_idx(0, j)}));
      visited[get_idx(0, j)] = 1;
      pq.push(wall({heightMap[m - 1][j], get_idx(m - 1, j)}));
      visited[get_idx(m - 1, j)] = 1;
    }
    for (size_t i = 1; i < m - 1; i++) {
      pq.push(wall({heightMap[i][0], get_idx(i, 0)}));
      visited[get_idx(i, 0)] = true;
      pq.push(wall({heightMap[i][n - 1], get_idx(i, n - 1)}));
      visited[get_idx(i, n - 1)] = true;
    }

    while (!pq.empty()) {
      auto [height, idx] = pq.top();
      pq.pop();

      const size_t r = idx / n;
      const size_t c = idx % n;

      if (r > 0 && !visited[get_idx(r - 1, c)]) {
        const size_t nr = r - 1;
        int new_height = heightMap[nr][c];
        water += max(0, height - new_height);
        pq.push({max(new_height, height), get_idx(nr, c)});
        visited[get_idx(nr, c)] = true;
      }
      if (r < m - 1 && !visited[get_idx(r + 1, c)]) {
        const size_t nr = r + 1;
        int new_height = heightMap[nr][c];
        water += max(0, height - new_height);
        pq.push({max(new_height, height), get_idx(nr, c)});
        visited[get_idx(nr, c)] = true;
      }
      if (c > 0 && !visited[get_idx(r, c - 1)]) {
        const size_t nc = c - 1;
        int new_height = heightMap[r][nc];
        water += max(0, height - new_height);
        pq.push({max(new_height, height), get_idx(r, nc)});
        visited[get_idx(r, nc)] = true;
      }
      if (c < n - 1 && !visited[get_idx(r, c + 1)]) {
        const size_t nc = c + 1;
        int new_height = heightMap[r][nc];
        water += max(0, height - new_height);
        pq.push({max(new_height, height), get_idx(r, nc)});
        visited[get_idx(r, nc)] = true;
      }
    }

    return water;
  }
};
