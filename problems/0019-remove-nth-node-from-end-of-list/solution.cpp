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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int sz = 0;
    ListNode *curr = head;
    while (curr) {
      curr = curr->next;
      sz++;
    }

    ListNode dummy = ListNode(0, head);

    curr = &dummy;
    for (int i = 0; i < sz - n; i++)
      curr = curr->next;

    ListNode *toRemove = curr->next;
    curr->next = toRemove->next;
    delete toRemove;

    return dummy.next;
  }
};
