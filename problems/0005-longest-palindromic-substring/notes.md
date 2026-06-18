### Manacher's Algorithm

This algorithm finds the longest palindromic substring by using palindrome's symmetric properties to avoid redundant calculations.

#### Prep

- Insert `#` between every character, and wrap the string with unique sentinels (e.g., `^` at the start, `$` at the end).

This transforms all palindromes (both even and odd lengths) into odd-length palindromes with a single, distinct center, while safely preventing out-of-bounds checks.

- `P[i]`: The radius of the longest palindrome centered at index `i`.
- `C`: The center of the palindrome extending furthest to the right.
- `R`: The right boundary of that palindrome ($R = C + P[C]$).

#### Mirror property (how calculations are skipped)

If `i` lies inside our current boundary (`i < R`):

- Its mirror index across the center `C` is `mirror = 2 * C - i`.
- By symmetry, the palindrome at `i` is guaranteed to be at least as large as the one at `mirror`, capped by the distance to the right boundary:
  $$P[i] = \min(R - i, P[\text{mirror}])$$

Now,

- **Expand:** Attempt to expand outwards from the pre-calculated radius `P[i]`.
- **Update:** If the newly expanded palindrome centered at `i` stretches past the current boundary `R`, update the active center and boundary:
  $$C = i, \quad R = i + P[i]$$

#### Getting the result

Find the maximum radius in `P`. The original palindrome's start index is `(center_index - max_radius) / 2`, and its length is `max_radius`.

---

- **Time Complexity:** $O(n)$
  - because only `R` moves right. We never do redundant character comparisions.
- **Space Complexity:** $O(n)$
  - for the helper array and preprocessed string.
