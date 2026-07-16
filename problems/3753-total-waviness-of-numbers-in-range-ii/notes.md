## State-Optimized Digit DP via Upward Contribution

### Intuition

**Waviness is a local property:** each interior digit forms a peak or valley relative to its two immediate neighbors. That means the entire sum across a range reduces to counting how many times each digit position contributes as a peak or valley. Digit DP fits naturally because the decision at each position depends only on the previous two digits and whether the number has started.

### Approach

Use memoized digit DP over the decimal representation to sum waviness contributions for all numbers upto $N$, then return $f(\text{num}_2) - f(\text{num}_1 - 1)$.

#### Prep

- `dp[rem][prev2][prev1][nonZero]` stores `{count, waviness}` for subproblems
  - `count`: the number of valid combinations formed by the remaining digits
  - `waviness`: the total waviness generated within those remaining digits
- `prev2` and `prev1` hold the last two digits placed, with $10$ meaning "none" (before the number starts)
- `nonZero` tracks whether any non-zero digit has been placed (the number has started)
- `small` flag tracks whether the prefix is already below the original bound

#### Logic

- **Wave Detection via Neighbor Comparison:**  
  When three consecutive digits exist ($\text{prev}_2 \ne 10$, $\text{prev}_1 \ne 10$, $\text{curr}$), a wave occurs if:
  - Valley: `prev2` > `prev1` < `curr`
  - Peak: `prev2` < `prev1` > `curr`

- **Contribution Aggregation:**  
  Instead of summing waviness at the leaf, propagate it upward. When a digit choice creates a wave, the wave counts for _every_ valid completion of the remaining positions.
  Add `next_result.count * wave_added` to the current result's waviness.

  **Crucially:** This allows us to remove the running `sum` from the DP state entirely, shrinking the memory footprint by a factor of `MAX_DIGITS - 2`!

- **Memoization on `small`:**  
  Cache only when `small == true` (tight bound has been released).  
  This avoids storing per-bound states while still reusing all fully-unconstrained suffixes

#### Getting the result

- Check if $\text{num} \le 100$ (too few digits, zero waviness)
- Extract digits in reverse (least significant first) and start DP from the most significant end
- The `count` field of the final DP result tracks total numbers processed, only `waviness` is returned

---

### Complexity

- **Time Complexity:** $O(D \cdot 11 \cdot 11 \cdot 2 \cdot 10) = O(\log_{10} X)$
  - max $D = 16$ digits (so $17$ possible `rem` values)
  - $11$ states each for `prev2` and `prev1` ($0-9$ and $10$)
  - $2$ states for `nonZero`
  - $10$ branches per state for digit generation
- **Space Complexity:** $O(D \cdot 11 \cdot 11 \cdot 2) = O(\log_{10} X)$
  - the size of the DP memoization table
