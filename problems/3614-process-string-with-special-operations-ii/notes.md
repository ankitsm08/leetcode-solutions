### Tracking K

If we store the resulting string, it may be as large as $10^15$ characters. That is too much ram.

To know what character is at `k` th index, we only need to track length as per the simulation. Then track k in a backward pass.

#### Forward Pass:

Simulate to find `len` at end of all operations.

- `*`: decrement `len`
- `#`: double `len`
- `%`: no change
- `a-z`: increment `len`

#### Backward Pass:

Simulate where `k` th character would end up.

- `*`: increment `len`
- `#`: half `len`, warp `k` if `k >= len`
- `%`: mirror `k` around the center by `k = len - k - 1`
- `a-z`: if `k == len - 1`, return the character. If not, decrement `len`
  - when `k == len - 1`, the character was inserted in that step, hence its the answer.

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$
