### Stack-based solution

Tracks indices of unmatched parentheses to compute valid segment lengths.

- stack stores indices of `(`
- sentinel `-1` is pushed initially to act as a base for length calculation
- on `(`: push its index
- on `)`:
  - pop once (attempt to match)
  - if stack becomes empty, push current index as new base
  - else, valid length is `i - stack.top()`
- `stack.top()` always points to the index just before the start of the current valid substring

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(n)$
  - stack worst case is storing all elements

---

### Two-pass solution (constant space)

#### Left -> Right pass

- `left`: count of `(`
- `right`: count of `)`
- if `left == right`, valid segment of length `2 * right`
- if `right > left`, reset counters (prefix cannot be part of a valid substring)

Handles cases with extra `)`.

#### Right -> Left pass

- same logic, but reversed
- if `left > right`, reset counters

Handles cases with extra `(`.

Combined, both passes cover all invalid prefix/suffix imbalance cases.

---

- **Time Complexity:** $O(2n)$
- **Space Complexity:** $O(1)$

---

### Notes

- stack solution models structure explicitly (matching indices)
- two-pass solution relies purely on balance constraints
- DP solution exists but is less direct and harder to reason about
