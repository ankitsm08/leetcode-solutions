## Min Heap (Priority Queue) Fronts

### Intuition

Merging two sorted lists is easy: two pointers, always take the smaller head. Merging $k$ of them naively would need $k-1$ pointers scanned against each other.

Here is the trick: at any moment we only care about the $k$ current heads, because the rest of each list is sorted and hides behind its head. So keep just those heads in a min heap and pull the smallest out. That is the whole merge.

### Approach

Heap-ify the first node of every list, then repeatedly pop the smallest node, append it to the output, and push its successor back in.

#### Prep

- `pq` holds the current head of every non-empty list, never more than $k$ nodes
- the heap stores raw `ListNode *`, so no `pair<int, ListNode *>` or index wrapper is needed
- `head` is a dummy `ListNode` sentinel so the first append needs no special case
- `curr` is the tail of the already built output chain, starts at `&head`

#### The Logic

- **Push successors, not sources:**  
  Popping a node exposes its `next`, and that node is now the fresh head of its list. Pushing it keeps the invariant "one head per live list", and popping the minimum always yields the global minimum among all remaining nodes.
- **Reuse the popped node:**  
  We relink `minNode` into the output instead of allocating a new node. Since every node is visited exactly once and its old `next` is overwritten by the following pop, no node is lost and no cycle forms.
- **Heap size stays at $k$:**  
  One pop and one push per output node, so the heap never grows past the number of input lists.

#### C++ Feature

- **`std::greater<ListNode *>` is out:**  
  It would need an `operator>` on `ListNode`, which does not exist.
- **The type must be written in full:**  
  CTAD cannot help here, `T` comes from the container and a lone `cmp` gives it nothing to deduce.
- **`decltype(cmp)` names the lambda type:**  
  A closure type has no name, so `decltype` on the variable is the only way to spell it out.

#### Getting the result

- `head.next` is the merged list, `nullptr` when every input was empty

---

### Complexity

- **Time Complexity:** $O(N \log k)$
  - $N$ total nodes, each costing one pop and one push on a heap of size at most $k$
  - seeding the heap is $O(k \log k)$, and $k \leq N$ whenever lists are non-empty
- **Space Complexity:** $O(k)$
  - at most one node reference per input list
