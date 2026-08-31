## Divide and Conquer with Fast Slow Middle

### Intuition

Sorted list is exactly the inorder of the balanced BST we want. To keep height balanced we need the middle element as root so left and right halves have almost equal size.

Tiny example `[-10, -3, 0, 5, 9]` -> middle `0` becomes root, `[-10, -3]` goes left, `[5, 9]` goes right, then we repeat inside each half.

### Approach

Find middle with fast slow pointers, split list into halves, recurse on each half to build subtrees.

#### Prep

- handle empty and single node via early returns before loop
- `slow` moves one step while `fast` moves two steps each time
- `slow_prev` trails `slow` to remember node before middle for splitting

#### The Logic

- **Middle via Fast Slow:**  
  With `fast` moving twice as fast, `slow` lands at middle when `fast` reaches end.  
  We pick upper middle for even length, both keep height diff $\le 1$

- **Prev Cut to Split:**  
  We cant cut a singly linked list without its predecessor.  
  Cutting after `slow_prev` isolates left part and `slow` next starts right part. Single node case already returned so `slow_prev` is always valid

- **Recursive Divide:**  
  Build root from `slow` value and recurse on left part and right part to fill subtrees.  
  Each call repeats the same middle split on its own sublist

#### Getting the result

- recursion bottoms at empty or single node and unwinds linking parents
- final root holds balanced BST whose inorder equals original list

---

### Complexity

- **Time Complexity:** $O(n \log n)$
  - each level scans all nodes, $O(n)$ per level over $O(\log n)$ levels
- **Space Complexity:** $O(\log n)$
  - recursion depth equals tree height, plus $O(n)$ for output tree itself
