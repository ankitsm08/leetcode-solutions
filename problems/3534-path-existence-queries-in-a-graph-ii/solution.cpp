#include <algorithm>
#include <array>
#include <bit>
#include <vector>

using namespace std;

class Solution {
  // log2(max(n) = 10^5)
  static constexpr int MAXN = 100001;
  static constexpr int K = bit_width(100001u);

  inline static array<int, K * MAXN> Jump;

public:
  vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                   vector<vector<int>> &queries) {
    vector<pair<int, int>> nodes;
    nodes.reserve(n);

    for (int i = 0; i < n; i++)
      nodes.emplace_back(nums[i], i);

    ranges::sort(nodes);

    vector<int> orig(n);
    for (int i = 0; i < n; i++) {
      orig[nodes[i].second] = i;
    }

    vector<int> component(n, 0);
    for (int component_id = 0, i = 1; i < n; i++) {
      component_id += nodes[i].first - nodes[i - 1].first > maxDiff;
      component[i] = component_id;
    }

    auto jump = [](int idx, int k) -> int & { return Jump[k * MAXN + idx]; };

    // base case
    for (int i = 0, j = 1; i < n; i++) {
      while (j < n && nodes[j].first <= nodes[i].first + maxDiff)
        j++;
      jump(i, 0) = j - 1;
    }

    // build sparse table
    for (int k = 1; k < K; k++) {
      for (int i = 0; i < n; i++)
        jump(i, k) = jump(jump(i, k - 1), k - 1);
    }

    vector<int> answer;
    answer.reserve(queries.size());

    for (const auto &query : queries) {
      int l = orig[query[0]], r = orig[query[1]];

      if (component[l] != component[r]) {
        answer.push_back(-1);
        continue;
      }

      int L = min(l, r), R = max(l, r);
      if (L == R) {
        answer.push_back(0);
        continue;
      }

      // binary jumping / lifting
      int steps = 0;
      for (int k = K - 1; k >= 0; k--) {
        if (jump(L, k) < R) {
          L = jump(L, k);
          steps += 1 << k;
        }
      }

      answer.push_back(steps + 1);
    }

    return answer;
  }
};
