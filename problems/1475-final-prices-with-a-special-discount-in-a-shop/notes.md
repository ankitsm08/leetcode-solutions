Classic **monotonic stack** problem.

For each price, we want the **nearest** _smaller-or-equal_ price to its right.  
We scan left to right and keep a **monotonic increasing stack of indices** (prices waiting for a discount)  
When a cheaper price appears, it resolves discounts for previous elements.

---

- **Time Complexity:** $O(n)$
  - each index is pushed and popped once
- **Space Complexity:** $O(n)$
  - stack may store all elements at max
