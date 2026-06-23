### 1D DP with Prefix Sums and Symmetry

This algorithm counts valid zigzag arrays by tracking the last number placed, using running totals and symmetry to optimize.

#### Prep

- The exact values of `[l, r]` don't matter, just the count of available numbers: $K = r - l + 1$.
- `dp[j]`: The number of valid zigzag arrays currently ending with the "value" `j`. (init to `1` for length `1`).

#### Tricks (how calculations are skipped)

- **Symmetry (half the work):**
  Every array that starts by going UP has a perfect mirror that starts by going DOWN.  
  We just track the state assuming the first move is an UP move,  
  and multiply the final answer by 2 at the end.

- **Alternating Prefix Sums (no inner loop):**
  - For an **UP** move, the previous number had to be strictly smaller. We just keep a running total `sum` instead of an inner loop
  - For a **DOWN** move, the previous number had to be strictly larger. We do the same running total, but reverse iterate
  - Simply alternate the loop direction depending on if `i` is odd or even

- **In-Place Updates (half the space):**
  Because we iterate in the exact direction the sum is growing, we don't need `curr` and `next` arrays.  
  Just store the old `dp[j]` in a `prev` variable,  
  overwrite `dp[j]` with the running `sum`,  
  and add `prev` to `sum` for the next loop.

- **Modulo Subtraction:**
  `% mod` is a slow CPU operation (same level as division).  
  Since we are only ever adding two numbers that are already `< mod`,  
  we just use `if (sum >= mod) sum -= mod`.  
  This saves ~10-40 cpu cycles each operation.

#### Getting the result

Sum up everything left in the `dp` array. Multiply by 2 (to account for the mirrored DOWN starting arrays), apply the modulo one last time, and return.

---

- **Time Complexity:** $O(n \cdot K)$
  - Loop `n` times, doing exactly `K` operations per loop
- **Space Complexity:** $O(K)$
  - Only a single 1D array of size `K`
