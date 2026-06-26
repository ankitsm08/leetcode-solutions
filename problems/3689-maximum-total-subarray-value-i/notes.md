## Intuition

Since we are allowed to overlap and repeat choices for the range of subarrays,  
the most optimal solution is obviously to take all the same subarrays which contain the `max` and `min` elements from given array.

This ensures `value` of each subarray is maximum thus maximizing the sum of values of all subarrays as they're independent of each other.

---

## Complexity

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$
