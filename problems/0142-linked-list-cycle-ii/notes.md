## Floyd's Tortoise and Hare (Cycle Meet + Reset)

### Intuition

We can detect a cycle with two pointers moving at different speeds, because inside a cycle one always laps the other and they must land on the same node. The neat part is that the meeting node is not the cycle entry, yet we can still recover the entry: the meeting point tells us how far we are around the loop, and from that we can back out how far the head is from the entry.

### Approach

Meet inside the cycle with slow/fast, then reset one pointer to the head and move both at equal speed until they collide again. That second collision is the cycle entry.

#### Prep

- `slow` steps 1 node per round, `fast` steps 2 nodes per round, both start at `head`
- loop only runs while `fast && fast->next`, so `fast` hitting the end means no cycle
- cycle length $L$, distance head to entry $x_1$, entry to meet $x_2$, meet forward to entry $x_3$, so $x_2 + x_3 = L$

#### The Logic

- **Relative speed kills the search:**  
  Each round `fast` gains exactly one node on `slow`. Inside a cycle of length $L$ the gap shrinks mod $L$, so it must hit zero within $L$ rounds. If `fast` dies first, the list is acyclic and we bail with `nullptr`

- **Why the second meeting is the entry:**  
  At the first meeting `slow` walked $x_1 + x_2$ and `fast` walked $2(x_1 + x_2)$. Same node means the difference is whole laps, so

  $$2(x_1 + x_2) - (x_1 + x_2) = x_1 + x_2 = mL \quad (m \ge 1)$$

  Solving for the head distance:

  $$x_1 = mL - x_2 = (m - 1)L + (L - x_2) = (m - 1)L + x_3$$

  So the head sits $x_3$ away from the entry plus $(m-1)$ full laps, meaning $x_1 \equiv x_3 \pmod{L}$. Both pointers now have the _same_ distance to the entry, up to whole laps. Walking both one step at a time from that point, `slow` cannot collide early (it is still outside the loop) and lands exactly on the entry at step $x_1$. `fast`, leaving from the meet node, covers $x_1$ steps too, and $x_1 \equiv x_3$ puts it right back on the entry in that same step.

#### Getting the result

- after `slow = head`, run both one step at a time until they are equal
- the shared node is the cycle entry, and no cycle means we already returned `nullptr`

---

### Complexity

- **Time Complexity:** $O(n)$
  - first loop is bounded by the distance to the entry plus one lap
  - second loop walks $x_1 \le n$ steps
- **Space Complexity:** $O(1)$
  - two raw pointers, no hash set and no node marking
