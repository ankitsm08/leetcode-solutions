#include <algorithm>
#include <cassert>

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
  int pairSum(ListNode *head) {

    ListNode *mid = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    // while (fast && fast->next)
    // but its guaranteed that length is even
    while (fast) {
      mid = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    // avoid memory leak by joining end of first half
    // to start of reversed second half
    mid->next = prev;

    ListNode *start = head;
    ListNode *end = prev;

    int max_sum = 0;
    while (end) {
      max_sum = max(max_sum, start->val + end->val);
      start = start->next;
      end = end->next;
    }

    return max_sum;
  }
};

int main() {
  Solution sol = Solution();
  {
    ListNode *head =
        new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    int sum = sol.pairSum(head);
    assert(sum == 6);
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      delete curr;
      curr = nextNode;
    }
  }
  {
    ListNode *head =
        new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));
    int sum = sol.pairSum(head);
    assert(sum == 7);
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      delete curr;
      curr = nextNode;
    }
  }
}
