## Two Pointers with Head Switching

### Intuition

Two intersecting lists share a common suffix starting at the intersection node, not just equal values. The suffix length is identical on both sides, so the only difference is the prefix before it.

We cant precompute lengths cheaply without extra passes, so we let each pointer compensate for the length difference by switching heads.

### Approach

Advance `a` and `b` together, switching each to the other list on `nullptr` until they meet.

#### Prep

- handle null inputs early to avoid unnecessary pointer switching
- `a` starts at `headA` and traverses first list then second
- `b` starts at `headB` and traverses second list then first

#### The Logic

Assuming, $c = $ number of common nodes.

- **Path equalization:**  
  Switching heads equalizes the total distance to $m + n + c$ so both pointers reach the intersection together if it exists. The longer prefix is offset by the extra walk on the other list.

- **Null meeting:**  
  If no intersection exists both pointers exhaust $m + n + 2c$ steps ($c = 0$) and meet at `nullptr`, which correctly signals no overlap. No extra flag is needed to distinguish this case.

#### Getting the result

- loop until `a == b` then return common node or `nullptr`
- alignment is implicit no length counting or extra storage used

---

### Complexity

- **Time Complexity:** $O(m + n + c)$
  - each pointer traverses at most $m + n + c$ nodes total
- **Space Complexity:** $O(1)$
  - only two pointers stored independent of list lengths
