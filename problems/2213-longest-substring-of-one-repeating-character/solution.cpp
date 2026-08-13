#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  struct Node {
    char pref_char = 0, suff_char = 0;
    int pref_len = 0, suff_len = 0, max_len = 0, len = 0;
  };

  class SegmentTree {
    int n;
    string s;
    vector<Node> tree;

    Node merge(const Node &L, const Node &R) {
      Node P;
      P.len = L.len + R.len;
      P.pref_char = L.pref_char;
      P.suff_char = R.suff_char;
      P.max_len = max(L.max_len, R.max_len);
      P.pref_len = L.pref_len;
      P.suff_len = R.suff_len;

      if (L.suff_char == R.pref_char) {
        P.max_len = max(P.max_len, L.suff_len + R.pref_len);

        if (L.pref_len == L.len) {
          P.pref_len = L.len + R.pref_len;
        }
        if (R.suff_len == R.len) {
          P.suff_len = R.len + L.suff_len;
        }
      }
      return P;
    }

    void build(int node, int L, int R) {
      if (L == R) {
        tree[node] = {.pref_char = s[L],
                      .suff_char = s[L],
                      .pref_len = 1,
                      .suff_len = 1,
                      .max_len = 1,
                      .len = 1};
        return;
      }
      int mid = L + (R - L) / 2;
      build(2 * node, L, mid);
      build(2 * node + 1, mid + 1, R);
      tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int L, int R, int idx, char ch) {
      if (L == R) {
        s[idx] = ch;
        tree[node] = {
            .pref_char = ch, .suff_char = ch, .pref_len = 1, .suff_len = 1, .max_len = 1, .len = 1};
        return;
      }
      int mid = L + (R - L) / 2;
      if (idx <= mid)
        update(2 * node, L, mid, idx, ch);
      else
        update(2 * node + 1, mid + 1, R, idx, ch);

      tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

  public:
    SegmentTree(const string &str) {
      s = str;
      n = static_cast<int>(s.length());
      tree.resize(4 * n);
      build(1, 0, n - 1);
    }

    void update(int idx, char ch) { update(1, 0, n - 1, idx, ch); }

    [[nodiscard]] inline int getMax() const { return tree[1].max_len; }
  };

public:
  vector<int> longestRepeating(const string &s, const string &queryCharacters,
                               vector<int> &queryIndices) {
    SegmentTree st(s);
    int k = static_cast<int>(queryIndices.size());
    vector<int> ans(k);

    for (int i = 0; i < k; i++) {
      st.update(queryIndices[i], queryCharacters[i]);
      ans[i] = st.getMax();
    }

    return ans;
  }
};
