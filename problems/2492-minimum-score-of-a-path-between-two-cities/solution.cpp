#include <algorithm>
#include <functional>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> parent, sz;

  int find_parent(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find_parent(parent[x]);
  }

  void union_node(int i, int j) {
    int a = find_parent(i);
    int b = find_parent(j);

    if (a == b)
      return;

    if (sz[a] < sz[b])
      swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
  }

  // INFO: Disjoint Set Union
  //
  int minScore(int n, vector<vector<int>> &roads) {
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto &road : roads)
      union_node(road[0], road[1]);

    int component_parent = find_parent(1);
    int min_score = numeric_limits<int>::max();

    for (auto &road : roads) {
      if (find_parent(road[0]) == component_parent) {
        min_score = min(min_score, road[2]);
      }
    }

    return min_score;
  }

  // INFO: Connected Component Traversal
  //
  // int minScore(int n, vector<vector<int>> &roads) {
  //   vector<vector<pair<int, int>>> graph(n);
  //   for (auto &road : roads) {
  //     graph[road[0] - 1].emplace_back(road[1] - 1, road[2]);
  //     graph[road[1] - 1].emplace_back(road[0] - 1, road[2]);
  //   }
  //
  //   vector<bool> visited(n, false);
  //   visited[0] = true;
  //
  //   stack<int> s;
  //   s.emplace(0);
  //
  //   int min_score = numeric_limits<int>::max();
  //
  //   while (!s.empty()) {
  //     int node = s.top();
  //     s.pop();
  //
  //     for (auto &[neighbor, dist] : graph[node]) {
  //       min_score = min(min_score, dist);
  //       if (!visited[neighbor]) {
  //         visited[neighbor] = true;
  //         s.emplace(neighbor);
  //       }
  //     }
  //   }
  //
  //   return min_score;
  // }
};
