#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  static inline stack<TreeNode *, vector<TreeNode *>> st;

public:
  TreeNode *recoverFromPreorder(const string &traversal) {
    const size_t n = traversal.length();

    size_t i = 0;
    while (i < n) {
      size_t depth = 0;
      while (i < n && traversal[i] == '-') {
        depth++;
        i++;
      }
      int nodeVal = 0;
      while (i < n && traversal[i] != '-') {
        nodeVal = nodeVal * 10 + (traversal[i++] - '0');
      }

      auto *node = new TreeNode(nodeVal);
      while (st.size() > depth)
        st.pop();

      if (!st.empty()) {
        TreeNode *parent = st.top();
        if (!parent->left)
          parent->left = node;
        else
          parent->right = node;
      }

      st.push(node);
    }

    while (st.size() > 1)
      st.pop();

    TreeNode *root = st.top();
    st.pop();

    return root;
  }
};
