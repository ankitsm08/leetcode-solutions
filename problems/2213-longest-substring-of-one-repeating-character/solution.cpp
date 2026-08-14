#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// INFO: Segment Tree
class Solution {
  struct Node {
    char left = 0, right = 0;
    int pref = 0, suff = 0, max_len = 0, len = 0;

    Node() = default;
    Node(char ch, int l) : left(ch), right(ch), pref(l), suff(l), max_len(l), len(l) {}
  };

  class SegmentTree {
    int n;
    string &s;
    vector<Node> tree;

    Node merge(const Node &L, const Node &R) {
      Node P;
      P.len = L.len + R.len;
      P.left = L.left;
      P.right = R.right;
      P.max_len = max(L.max_len, R.max_len);
      P.pref = L.pref;
      P.suff = R.suff;

      if (L.right == R.left) {
        P.max_len = max(P.max_len, L.suff + R.pref);

        if (L.pref == L.len)
          P.pref = L.len + R.pref;

        if (R.suff == R.len)
          P.suff = R.len + L.suff;
      }
      return P;
    }

    void build(int node, int L, int R) {
      if (L == R) {
        tree[node] = Node(s[L], 1);
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
        tree[node] = Node(ch, 1);
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
    SegmentTree(string &str) : s(str) {
      n = static_cast<int>(str.length());
      tree.resize(4 * n);
      build(1, 0, n - 1);
    }

    inline void update(int idx, char ch) { update(1, 0, n - 1, idx, ch); }

    [[nodiscard]] inline int getMax() const { return tree[1].max_len; }
  };

public:
  vector<int> longestRepeating(string &s, const string &queryCharacters,
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
