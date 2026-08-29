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
  ListNode *partition(ListNode *head, int x) {
    if (!head)
      return head;

    ListNode dummyFront{0}, dummyBack{0};
    ListNode *front = &dummyFront, *back = &dummyBack;

    for (ListNode *curr = head; curr; curr = curr->next) {
      if (curr->val < x) {
        front->next = curr;
        front = front->next;
      } else {
        back->next = curr;
        back = back->next;
      }
    }

    back->next = nullptr;
    front->next = dummyBack.next;

    return dummyFront.next;
  }
};
