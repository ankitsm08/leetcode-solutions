#include <memory_resource>
#include <unordered_map>

using namespace std;

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

// INFO: O(1) Space Interleaving
class SolutionInterleave {
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

// INFO: O(n) Space Hash Map
class SolutionHashMap {
  pmr::unsynchronized_pool_resource pool;

public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    pmr::unordered_map<Node *, Node *> map(&pool);

    Node *curr = head;
    Node *copyHead = new Node(curr->val);
    Node *copy = copyHead;
    map[head] = copyHead;
    curr = curr->next;

    while (curr) {
      Node *nextCopy = new Node(curr->val);
      map[curr] = nextCopy;
      copy->next = nextCopy;
      copy = nextCopy;
      curr = curr->next;
    }

    curr = head;
    copy = copyHead;
    while (curr) {
      copy->random = map[curr->random];
      curr = curr->next;
      copy = copy->next;
    }

    return copyHead;
  }
};
