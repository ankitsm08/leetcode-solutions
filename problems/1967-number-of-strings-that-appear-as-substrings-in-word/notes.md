## Knuth-Morris-Pratt Algorithm

### Intuition

Saw the naive find loop and thought why not practice KMP even if constraints are tiny.

### Approach

Precompute failure links for each pattern then search with smart backtracking instead of naive checks.

#### Prep

- allocate reusable LPS array sized to word length
- for each pattern skip if longer than word
- reset only first `m` slots of LPS before building table

#### The Logic

- **LPS Table:**  
  Builds Longest Prefix that is also suffix so we never recheck matched characters.  
  Skips redundant comparisons when mismatch happens
- **Smart Backtrack:**  
  On mismatch jump `j` to `lps[j - 1]` instead of resetting to zero.  
  Avoids restarting from beginning of pattern

#### Getting the result

Once `j` hits pattern length we found a match so increment count and break to next pattern

---

### Complexity

Where `k` is the number of patterns, `n` is length of word and `m` is length of each pattern:

- **Time Complexity:** $O(n \cdot k + \sum m)$
  - because lps build is linear per pattern and we build LPS vector for each pattern
- **Space Complexity:** $O(n)$
  - just one reused LPS vector across all patterns (to avoid repeated allocations)
  - could have used LPS the size of the pattern ( $O(\max(m))$ )
