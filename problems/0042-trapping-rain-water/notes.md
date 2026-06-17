Solved using **Two Pointers**.

We keep two pointers at both ends and track the tallest wall seen so far from each side.  
Water at any position is decided by the smaller of `leftMax` and `rightMax`.  
Move the pointer with the smaller max, because that side is the limiting wall.  
At each step, add (`currentMax − height[i]`) to the answer.

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $(1)$
