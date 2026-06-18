Handle special case for first and last row with equal gaps in characters.

Handle middle rows by using alterate distance to characters pattern with precomputed distances relative to row number.

This lets us solve the problem without using any extra space.

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$
