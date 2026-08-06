#include <numeric>
#include <vector>

using namespace std;

class Solution {
  struct Edge {
    int to;
    int next;
    Edge(int t, int n) : to(t), next(n) {}
  };

  static constexpr int MAX_N = static_cast<int>(1e5);

  static inline vector<Edge> edges;
  static inline vector<int> head = vector<int>(MAX_N, -1);
  static inline vector<bool> visited = vector<bool>(MAX_N, false);
  static inline vector<int> dfs_stack;

  inline void addEdge(int u, int v) {
    edges.emplace_back(v, head[u]);
    head[u] = static_cast<int>(edges.size() - 1);
  }

public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    edges.clear();

    for (const auto &edge : invocations)
      addEdge(edge[0], edge[1]);

    dfs_stack.push_back(k);
    visited[k] = true;

    while (!dfs_stack.empty()) {
      int u = dfs_stack.back();
      dfs_stack.pop_back();

      for (int idx = head[u]; idx != -1; idx = edges[idx].next) {
        const int v = edges[idx].to;
        if (!visited[v]) {
          visited[v] = true;
          dfs_stack.push_back(v);
        }
      }
    }

    head.assign(n, -1);

    vector<int> remaining;

    for (const auto &edge : invocations) {
      if (!visited[edge[0]] && visited[edge[1]]) {
        visited.assign(n, false);

        remaining.resize(n);
        iota(remaining.begin(), remaining.end(), 0);
        return remaining;
      }
    }

    for (int i = 0; i < n; i++) {
      if (!visited[i])
        remaining.push_back(i);
      else
        visited[i] = false;
    }

    return remaining;
  }
};
