#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    const auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    for (auto list : lists) {
      if (list)
        pq.push(list);
    }

    ListNode head;
    ListNode *curr = &head;

    while (!pq.empty()) {
      auto minNode = pq.top();
      pq.pop();
      if (minNode->next)
        pq.push(minNode->next);

      curr->next = minNode;
      curr = curr->next;
    }
    curr->next = nullptr;

    return head.next;
  }
};
