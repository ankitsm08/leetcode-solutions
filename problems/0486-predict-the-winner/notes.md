## Minimax Interval DP

### Intuition

This is a zero-sum game, so we only need the score difference, not both scores. On any interval, the current player picks an end, banks its value, and hands the smaller interval to the opponent with roles swapped. Since the opponent now maximizes their own difference, the value of an interval is the picked end minus the opponent's best difference on what remains. That is a minimax recurrence over intervals, solvable by DP.

Even-length arrays never need the DP: player 1 can force taking an entire parity class of indices (all odd or all even) by always grabbing the matching end. The richer parity class sums to at least half the total, so player 1 wins outright (ties count as wins). Only odd $n$ reaches the table.

### Approach

Compute the best score difference the player to move can force on every interval, then read the answer off the full-array state.

#### Prep

- `dp[j]` stores best difference for interval `[i..j]` during row `i`
- iterate `i` descending so results from row `i + 1` stay intact
- even-length input returns `true` before any DP runs

#### Logic

- **Parity Shortcut:**
  With even length, taking either end locks player 1 into one parity class of indices, so they pick the class with the bigger sum and never lose.

- **Difference Minimax Recurrence:**
  `dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])` banks the picked end, then subtracts the opponent's best difference on the leftover interval `[i + 1..j]` or `[i..j - 1]`.

- **1D Row Rolling:**
  The 2D recurrence only touches row $i + 1$ and the current row's previous column, so a single array reusing stale row $i + 1$ values is enough; `dp[i] = nums[i]` seeds the base case.

- **Flattened Memo (recursive):**
  The top-down twin caches `maxDiff(i, j)` in `dp[i * MAX_N + j]`, collapsing the small interval grid into one array.

#### Getting the result

- iterative answer is `dp[n - 1] >= 0`, since ties count as a win
- recursive answer is `maxDiff(0, n - 1) >= 0` on the full interval

---

### Complexity

- **Time Complexity:** $O(n^2)$
  - every interval pair $(i, j)$ computed once with constant work
  - for even $n$: $O(1)$
    - parity shortcut skips the table entirely
- **Space Complexity:**
  - iterative: $O(n)$
    - single rolling row of length $n$
  - recursive: $O(n^2)$
    - flattened memo table plus $O(n)$ recursion depth
