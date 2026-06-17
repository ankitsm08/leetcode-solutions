Use two pointers -> moving towards each other. The one to move is the smaller of the two.

- `width` = `right - low`
- `height` = `min(height[left], height[right])`

Calcuate area, and keep track of maximum.

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$
