#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  using Block = pair<int, int>;
  static inline vector<Block> blocks;
  static inline vector<int> pair_sums;
  static inline vector<int> ST;
  static inline vector<int> char_to_block;

  inline int ilog2(int x) { return 31 - __builtin_clz(x); }

public:
  vector<int> maxActiveSectionsAfterTrade(const string &s, vector<vector<int>> &queries) {
    const int n = static_cast<int>(s.length());

    blocks.resize(0);
    char_to_block.assign(n, -1);
    int total_ones = 0;

    for (int i = 0; i < n;) {
      if (s[i] == '1') {
        total_ones++;
        i++;
      } else {
        int start = i;
        int block_id = static_cast<int>(blocks.size());
        while (i < n && s[i] == '0') {
          char_to_block[i] = block_id;
          i++;
        }
        blocks.emplace_back(start, i - 1);
      }
    }

    const int m = static_cast<int>(blocks.size());
    pair_sums.clear();
    if (m > 1) {
      pair_sums.resize(m - 1);
      for (int i = 0; i < m - 1; i++) {
        const int len1 = blocks[i].second - blocks[i].first + 1;
        const int len2 = blocks[i + 1].second - blocks[i + 1].first + 1;
        pair_sums[i] = len1 + len2;
      }
    } else
      return vector<int>(queries.size(), total_ones);

    // sparse table
    const int k = ilog2(m - 1) + 1;
    ST.resize((m - 1) * k, 0);
    auto st = [&](int i, int j) -> int & { return ST[i * k + j]; };

    for (int i = 0; i < m - 1; i++)
      st(i, 0) = pair_sums[i];

    for (int j = 1; j < k; j++) {
      for (int i = 0; i + (1 << j) <= m - 1; i++)
        st(i, j) = max(st(i, j - 1), st(i + (1 << (j - 1)), j - 1));
    }

    auto query_st = [&](int L, int R) {
      if (L > R)
        return 0;
      int j = ilog2(R - L + 1);
      return max(st(L, j), st(R - (1 << j) + 1, j));
    };

    auto trim_len = [&](int idx, int l, int r) {
      int intersect_start = max(blocks[idx].first, l);
      int intersect_end = min(blocks[idx].second, r);
      return max(0, intersect_end - intersect_start + 1);
    };

    vector<int> ans;
    ans.reserve(queries.size());

    for (const auto &q : queries) {
      const int l = q[0], r = q[1];

      // first block inside or crossing 'l'
      int first_idx = char_to_block[l];
      if (first_idx == -1) {
        int temp = l;
        while (temp <= r && char_to_block[temp] == -1)
          temp++;
        first_idx = (temp <= r) ? char_to_block[temp] : m;
      }

      // last block inside or crossing 'r'
      int last_idx = char_to_block[r];
      if (last_idx == -1) {
        int temp = r;
        while (temp >= l && char_to_block[temp] == -1)
          temp--;
        last_idx = (temp >= l) ? char_to_block[temp] : -1;
      }

      // 0 or 1 block
      if (first_idx == m || last_idx == -1 || first_idx >= last_idx) {
        ans.push_back(total_ones);
        continue;
      }

      // exactly 2 blocks
      if (last_idx == first_idx + 1) {
        const int delta = trim_len(first_idx, l, r) + trim_len(last_idx, l, r);
        ans.push_back(total_ones + delta);
        continue;
      }

      // 3 or more blocks
      const int len_second = blocks[first_idx + 1].second - blocks[first_idx + 1].first + 1;
      const int left_edge = trim_len(first_idx, l, r) + len_second;

      const int len_second_last = blocks[last_idx - 1].second - blocks[last_idx - 1].first + 1;
      const int right_edge = len_second_last + trim_len(last_idx, l, r);

      int middle = query_st(first_idx + 1, last_idx - 2);

      ans.push_back(total_ones + max({left_edge, right_edge, middle}));
    }

    return ans;
  }
};
