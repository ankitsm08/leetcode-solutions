Use binary search over ascending order of integers to find the square root.

- precompute `floor(sqrt(INT_MAX))` = `46340`, avoiding integer overflow and skipping unnecessary calculations
- use binary search with `low` = `0`, `high` = `46340`
- if no match, `high` is the answer since its equal to `floor(sqrt(x))` as `high` = `mid - 1` in last step

---

- **Time Complexity:** $O(\log x)$
- **Space Complexity:** $O(1)$
