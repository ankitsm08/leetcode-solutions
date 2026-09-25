/*
// Definition for a Node.
*/
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    Node *curr = head;
    while (curr) {
      Node *copy = new Node(curr->val);
      copy->next = curr->next;
      curr->next = copy;
      curr = copy->next;
    }

    curr = head;
    while (curr) {
      Node *copy = curr->next;
      if (curr->random)
        copy->random = curr->random->next;
      curr = copy->next;
    }

    curr = head;
    Node *copy = head->next;
    Node *copyHead = head->next;
    while (curr) {
      curr->next = curr->next->next;
      if (copy->next)
        copy->next = copy->next->next;
      curr = curr->next;
      copy = copy->next;
    }

    return copyHead;
  }
};
