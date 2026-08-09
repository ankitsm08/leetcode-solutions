## Maximal-Square DP with Binary Search

### Intuition

The answer is just $k^2$, so the whole fight reduces to finding the largest side $k$ for which two disjoint all-ones squares of size $k$ exist.  
**Feasibility is monotonic:** shrinking a valid pair keeps it valid, so we can binary-search $k$. The expensive part is testing one $k$ cheaply, and the maximal square DP answers every reachability query in constant time.

### Approach

Precompute the largest all-ones square ending at each cell, then binary search the largest $k$ whose candidate pairs stay disjoint.

#### Prep

- `dp[i][j]` stores the largest all-ones square anchored at $(i, j)$ bottom-right
- seed the DP base row and column so the recurrence has a first edge
- track `maxSide` during the DP to cap the binary-search top end
- no early count guard needed, a `best` of $0$ covers impossible cases

#### The Tricks

- **Maximal-Square DP:**  
  On a $1$ cell, `dp[i][j]` $= 1 + \min($`dp[i-1][j]`, `dp[i][j-1]`, `dp[i-1][j-1]`$)$  
  The tightest of the three neighbors plus one.  
  A $0$ cell stays $0$, and $dp(i, j) \ge k$ means a $k \times k$ square ends exactly there

- **Early-Exit Overlap Test:**  
  Track `rMin`, `rMax`, `cMin`, `cMax` over the top-left corners seen so far.

  Before merging a new corner, compare it against every extreme:
  - No vertical overlap: $r - rMin \ge k$ and $rMax - r \ge k$
  - No horizontal overlap: $c - cMin \ge k$ and $cMax - c \ge k$

  Each test asks whether that extreme corner is at least $k$ apart on one axis, which makes the two squares disjoint

- **Sufficient Extremes Only:**  
  A corner is disjoint from some earlier one exactly when it clears an extreme by $k$ on some axis, so min/max tracking beats checking all pairs.  
  Row-major scanning plus immediate returns means most inputs never pay the full grid pass

- **Binary Search Over Answer:**  
  Search $k$ in $[1, \text{maxSide}]$ while remembering the best feasible side.  
  When even $k = 1$ fails, `best` never moves from its $0$ default

#### Getting the result

- return `best * best`, the area of each square at the largest feasible side
- `best` stays $0$ when two non-overlapping cells cannot be found, so impossible inputs answer $0$

---

### Complexity

- **Time Complexity:** $O(mn \log \min(m, n))$
  - DP fills the grid in $O(mn)$
  - each feasibility check scans all cells over $\log (\text{maxSide})$ bisection steps
- **Space Complexity:** $O(mn)$
  - the DP table holds one slot per cell
