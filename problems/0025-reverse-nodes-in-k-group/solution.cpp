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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prevGroupTail = &dummy;

    while (true) {
      ListNode *kth = prevGroupTail;
      for (int i = 0; i < k && kth; i++) {
        kth = kth->next;
      }

      if (!kth)
        break;

      ListNode *nextGroupHead = kth->next;

      ListNode *curr = prevGroupTail->next;
      ListNode *prev = nullptr;

      prevGroupTail->next = kth;
      prevGroupTail = curr;

      while (curr != nextGroupHead) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      }

      prevGroupTail->next = nextGroupHead;
    }

    return dummy.next;
  }
};
