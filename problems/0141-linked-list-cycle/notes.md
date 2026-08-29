## Floyd's Tortoise and Hare (Two Pointers)

### Intuition

A cycle makes the linked list infinite if we keep following `next` pointers without stopping. We cant afford a visited set for $O(1)$ space, so we need a way to detect looping without remembering every node.

If a faster pointer chases a slower one inside a loop, the distance between them shrinks by one each step and they must eventually meet.

### Approach

Race `slow` by one and `fast` by two and report cycle if they ever coincide.

#### Prep

- `slow` starts at `head` and advances one node per step
- `fast` starts at `head` and advances two nodes per step
- handle empty and single node lists via null checks upfront

#### The Logic

- **Speed gap:**  
  If a cycle exists the faster pointer must eventually lap the slower one inside the loop. The gap closes by one per iteration so meeting is guaranteed within $n$ steps.

- **Null guard:**  
  Checking `fast` and `fast->next` before jumping prevents dereferencing `nullptr` on acyclic lists. This guard naturally terminates the race when no cycle exists.

#### Getting the result

- if pointers meet at any iteration cycle exists return true
- if `fast` hits `nullptr` traversal ends no cycle found

---

### Complexity

- **Time Complexity:** $O(n)$
  - single pass where `fast` visits at most $n$ nodes
- **Space Complexity:** $O(1)$
  - only two pointer variables independent of input size
