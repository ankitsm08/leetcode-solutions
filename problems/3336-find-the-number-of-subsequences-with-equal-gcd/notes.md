## Mobius Inverse with Inclusion-Exclusion or DP with GCD State

<!-- TODO: -->

> I will learn how to do the solution with Mobius Inverse with Inclusion-Exclusion and update my solution later.

### Intuition

Brute force over all subsequence pairs is impossible. The key is that both sequences must have the same GCD, and we only care about the GCD of each sequence, not the actual elements. This lets us fold the decision per element into a compact DP over GCD states.

### Approach

Process elements one by one, tracking `dp[j][k]` = number of ways where seq1 has GCD j and seq2 has GCD k.  
For each element, we skip it, add it to seq1, or add it to seq2.

#### Prep

- precompute a 2D gcd table for all pairs up to 200, since `nums[i] <= 200`
- `dp[0][0] = 1` initially, representing both subsequences empty (GCD 0)
- `m` is the max element, bounding the GCD states we need to track

#### The Logic

- **Three-Way Transition:**  
  For each state `(j, k)` with value `v`:
  - skip: `dp[j][k] += v`
  - put in seq1: `dp[gcd(j, num)][k] += v`
  - put in seq2: `dp[j][gcd(k, num)] += v`
- **GCD of empty set is 0:** `gcd(0, x) = x`  
  So the first element added to an empty sequence sets its GCD to that element naturally
- **Rolling array:**  
  Only two layers are needed (`curr`, `next`), toggled per element

#### Getting the result

- sum `dp[i][i]` for `i` from `1` to `m` (both sequences non-empty with equal GCD)
- apply modulo throughout

---

### Complexity

- **Time Complexity:** $O(n \cdot m^2)$
  - two nested loops over GCD states up to m per element, plus gcd lookup is O(1)
- **Space Complexity:** $O(m^2)$
  - two layers of a 2D arrays
