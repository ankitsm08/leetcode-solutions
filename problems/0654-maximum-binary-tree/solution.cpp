#include <limits>
#include <stack>
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
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    stack<TreeNode *> s;
    TreeNode sentinel(numeric_limits<int>::max());
    s.push(&sentinel);

    for (int num : nums) {
      auto *node = new TreeNode(num);

      TreeNode *last = nullptr;
      while (s.top()->val < num) {
        last = s.top();
        s.pop();
      }

      node->left = last;
      s.top()->right = node;
      s.push(node);
    }

    return sentinel.right;
  }
};
