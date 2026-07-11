#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  struct DSU {
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
      parent.resize(n + 1);
      iota(parent.begin(), parent.end(), 0);
      sz.resize(n + 1, 1);
    }

    int find_parent(int node) {
      return parent[node] == node ? node : parent[node] = find_parent(parent[node]);
    }

    void union_node(int node1, int node2) {
      int a = find_parent(node1);
      int b = find_parent(node2);
      if (a == b)
        return;

      if (sz[a] < sz[b])
        swap(a, b);

      parent[b] = a;
      sz[a] += sz[b];
    }
  };

  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    struct DSU dsu(n);

    for (const auto &edge : edges)
      dsu.union_node(edge[0], edge[1]);

    vector<int> edge_count(n, 0);
    for (const auto &edge : edges)
      edge_count[dsu.find_parent(edge[0])]++;

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dsu.parent[i] == i) {
        int v_count = dsu.sz[i];
        int e_count = edge_count[i];

        ans += e_count == (v_count * (v_count - 1) >> 1);
      }
    }

    return ans;
  }
};
