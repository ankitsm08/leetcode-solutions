## Sliding Window / Two Pointers

### Intuition

We need to track occurrences of 'a', 'b', and 'c' across substrings. A standard nested loop is too slow, but if a window becomes valid, every character added afterward also forms a valid substring.

### Approach

Expand a window to find valid sets, then shrink from the left to count all possible prefixes simultaneously.

#### Prep

- track character counts using a fixed size array of size three
- left and right pointers define the current sliding window boundary
- variable substrings stores the running total of valid strings found

#### The Logic

- **Prefix Accumulation:** When the window contains all three characters, shrinking it tells us how many valid prefixes exist.  
  Every character left of the current left pointer forms a unique valid substring ending at right.  
  Adding left directly to the count skips checking those prefixes individually.  
  This brings the time down from quadratic to linear.

---

### Complexity

- **Time Complexity:** $O(n)$
  - right pointer passes over the string exactly once
- **Space Complexity:** $O(1)$
  - frequency tracking array uses a constant three integers of memory
