Essentially same as the previous problem 153 (except this has duplicate values in the array).

The key is to take baby steps when we cant decide how to split in half (i.e. when `mid` == `high`), by decrementing `high`.

---

- **Time Complexity:**
  - Average: $O(\log n)$
  - Worst Case: $O(\log n)$
- **Space Complexity:** $O(1)$
