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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy{0, head};
    ListNode *prev = &dummy;

    while (prev->next) {
      ListNode *curr = prev->next;
      if (curr->next && curr->val == curr->next->val) {
        int val = curr->val;

        while (prev->next && prev->next->val == val) {
          ListNode *dupNode = prev->next;
          prev->next = dupNode->next;

          delete dupNode;
        }
      } else {
        prev = prev->next;
      }
    }

    return dummy.next;
  }
};
