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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;

    ListNode *last = head;

    int sz = 1;
    while (last->next) {
      last = last->next;
      sz++;
    }

    k %= sz;
    if (k == 0)
      return head;

    ListNode *end = head;
    for (int i = 0; i < sz - k - 1; i++)
      end = end->next;

    ListNode *newStart = end->next;

    end->next = nullptr;
    last->next = head;

    return newStart;
  }
};
