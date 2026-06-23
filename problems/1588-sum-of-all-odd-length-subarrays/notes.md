Each element contributes to the answer as many times as it appears in odd-length subarrays, so count that directly instead of generating subarrays.

For index `i`,

- `left = i + 1`
- `right = n - i`
- total subarrays containing `i`: `total` = `left * right`

Odd-length subarrays is exactly `ceil(total / 2)`

---

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
