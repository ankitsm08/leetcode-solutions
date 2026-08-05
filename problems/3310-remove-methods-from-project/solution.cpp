#include <bitset>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_N = static_cast<int>(1e5);
  static inline bitset<MAX_N> visited;

public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    vector<vector<int>> edges(n);

    for (const auto &edge : invocations) {
      edges[edge[0]].push_back(edge[1]);
    }

    visited.reset();
    queue<int> q;
    q.push(k);
    visited.set(k);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : edges[u]) {
        if (!visited.test(v)) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    vector<int> remaining;

    for (const auto &edge : invocations) {
      if (!visited.test(edge[0]) && visited.test(edge[1])) {
        remaining.resize(n);
        iota(remaining.begin(), remaining.end(), 0);
        return remaining;
      }
    }

    for (int i = 0; i < n; i++) {
      if (!visited.test(i))
        remaining.push_back(i);
    }

    return remaining;
  }
};
