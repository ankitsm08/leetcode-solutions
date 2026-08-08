## Greedy with Backward Suffix Feasibility

### Intuition

A valid sequence is an increasing index list in `word1` whose characters, with at most one replaced, spell out `word2`. The lexicographically smallest sequence wants the earliest possible index at every step, so we greedily walk `word1` left to right. The catch is the single substitution: we need to know before spending it at a position whether the rest of `word2` can still be matched afterwards. That depends only on the remaining suffix.

### Approach

Precompute the leftmost index where each suffix of `word2` can still fit in `word1`, then pick the smallest feasible index for each character, spending the one substitution only when forced.

#### Prep

- `last[i]` stores the leftmost `word1` index where suffix `word2[i..]` can still match
- `changed` flags whether the single substitution has already been used
- `last[m] = n` acts as a sentinel, making an empty suffix always feasible
- `ans` is the output array holding up to $m$ chosen indices
- we fill the `word2` prefix counter `i` as we greedily advance

#### Logic

- **Backward Feasibility Sweep:**  
  Walk `word2` from right to left and retreat `j` until `word2[i] == word1[j]`  
  The stored `last[i] = j` becomes the farthest-left anchor that just keeps the rest matchable, so the check `last[i + 1] > j` answers "suffix fits after `j`" in $O(1)$
- **Forward Decision Rule:**  
  Take the current `word1[j]` into `ans` when it equals `word2[i]`, or when the swap is unused and `last[i + 1] > j`  
  The second branch keeps the sequence valid by only substituting when the remaining suffix survives strictly after `j`

#### Getting the result

- the greedy loop fills `ans[0..m)` with the earliest feasible indices
- return those $m$ entries if the loop fully matched `word2`, else an empty vector

### Complexity

- **Time Complexity:** $O(n + m)$
  - backward sweep walks `j` left at most $n$ positions total, forward sweep visits $n$ chars
- **Space Complexity:** $O(n)$
  - `last` and `ans` scale linearly with input
