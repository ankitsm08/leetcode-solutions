#include <queue>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return nullptr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *right = nullptr;
      for (size_t i = q.size(); i > 0; i--) {
        Node *curr = q.front();
        q.pop();
        curr->next = right;
        right = curr;
        if (curr->left) {
          q.push(curr->right);
          q.push(curr->left);
        }
      }
    }

    return root;
  }
};
