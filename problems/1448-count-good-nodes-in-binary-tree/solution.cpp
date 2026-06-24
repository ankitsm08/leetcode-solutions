#include <algorithm>

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
public:
  int good_dfs(TreeNode *node, int branch_max) {
    if (!node)
      return 0;

    int new_max = max(branch_max, node->val);
    return (branch_max <= node->val) + good_dfs(node->left, new_max)
           + good_dfs(node->right, new_max);
  }

  int goodNodes(TreeNode *root) { return good_dfs(root, root->val); }
};
