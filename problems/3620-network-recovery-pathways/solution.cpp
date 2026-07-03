#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k) {
    const int n = static_cast<int>(online.size());
    using ll = long long;

    vector<vector<pair<int, int>>> graph(n);
    int max_edge = 0;

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], weight = edge[2];
      if (!online[u] || !online[v])
        continue;
      graph[u].emplace_back(v, weight);
      max_edge = max(max_edge, weight);
    }

    vector<ll> memo(n, -1);

    auto check = [&](int X) -> ll {
      fill(memo.begin(), memo.end(), -1);

      // recursive dfs
      auto dfs = [&](auto &self, int node) -> ll {
        if (node == n - 1)
          return 0;

        if (memo[node] != -1)
          return memo[node];

        ll min_cost = numeric_limits<ll>::max();

        for (const auto &[neighbor, weight] : graph[node]) {
          if (weight < X)
            continue;

          ll cost_from_neighbor = self(self, neighbor);

          if (cost_from_neighbor != numeric_limits<ll>::max()) {
            min_cost = min(min_cost, static_cast<ll>(weight) + cost_from_neighbor);
          }
        }

        return memo[node] = min_cost;
      };

      return dfs(dfs, 0);
    };

    // binary search over answer
    int low = 0;
    int high = max_edge;
    int best_score = -1;

    while (low <= high) {
      int mid = low + ((high - low) >> 1);

      if (check(mid) <= k) {
        best_score = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return best_score;
  }
};
