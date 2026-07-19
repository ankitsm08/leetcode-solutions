## Monotonic Stack with Greedy Lookahead

### Intuition

The naive subset enumeration is impossible at $O(2^n)$, so we need a constructive greedy. When building left to right, if a larger character appears before a smaller one and the larger one also appears again later, we can safely discard the earlier copy. This gives a monotonic stack that pops whenever a later character is smaller and the popped char has a future occurrence.

### Approach

Scan once with a stack of chosen characters and a precomputed rightmost-index map to decide whether a larger top can be safely dropped.

#### Prep

- map each character to its last index in the string
- keep a membership set for characters already in the stack
- the stack (`string`) doubles as the result accumulator

#### The Logic

- **Pop-if-removable:**  
  Use suffix visibility to undo a suboptimal earlier decision.  
  While:
  - the stack is nonempty
  - the current character is smaller than the top
  - the top character appears again later, pop the top

- **Skip-if-already-placed:**  
  If the current character is already in the stack, skip it. Duplicates cant help and would break the distinct-character constraint

#### Getting the result

- the stack (final `string`), read bottom to top, is the lexicographically smallest subsequence containing every distinct character exactly once

---

### Complexity

- **Time Complexity:** $O(n)$
  - each character pushed and popped at most once
- **Space Complexity:** $O(1)$
  - the map and set are fixed to the alphabet size
  - the stack holds at most one of each character
