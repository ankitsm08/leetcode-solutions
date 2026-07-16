## Linear Recurrence Precomputation

### Intuition

Waviness depends only on three consecutive digits at a time. When we extend `i / 10` to `i`, the only fresh peak or valley candidate is what used to be the last digit, now it has neighbors on both sides. Everything before that was already counted in `dp[i / 10]`.

### Approach

Slide a 3-digit window rightward and reuse the waviness of the prefix via a simple recurrence.

#### Prep

- `dp[i]`: waviness of the single number `i`
- `pref[i]`: sum of `dp[1..i]`, the answer for range `[1, i]`
- `MAX = 100001` because constraints are up to $10^5$

#### The Trick

- **Digit Recurrence:**  
  For `i >= 101`, grab the last three digits:  
  `l = (i / 100) % 10`, `m = (i / 10) % 10`, `r = i % 10`  
  The middle one `m` was previously ineligible (rightmost) and now has two neighbours  
  `dp[i] = dp[i / 10] + (m is peak or valley)`
- **Prefix Accumulation:**  
  `pref[i] = pref[i - 1] + dp[i]`, computed in the same pass

#### Getting the result

- `totalWaviness(A, B) = pref[B] - pref[A - 1]`, two array lookups

---

### Complexity

- **Time Complexity:** $O(1)$
  - single linear pass up to $10^5$ once
  - then $O(1)$ per query
- **Space Complexity:** $O(1)$
  - two arrays of constant size `MAX`
