Assume `high` always stays on the right sorted portion (end index).

Binary search comparing to `high` and shift `low` = `mid + 1` if `mid` is higher than `high`, which means low is in the left sorted portion.

At the end, `low` = `high` and that's the answer.

---

- **Time Complexity:** $O(\log n)$
- **Space Complexity:** $O(1)$
