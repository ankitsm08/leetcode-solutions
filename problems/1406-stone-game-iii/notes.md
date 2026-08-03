## Minimax DP with Score Difference

### Intuition

Both players play optimally, so whoever moves picks the move that maximizes his own edge. We dont need to track Alice and Bob's absolute scores. A single value, the current player's score minus the opponent's score from a suffix, captures everything. Each turn the mover grabs $1$, $2$, or $3$ stones, then roles swap, so the recurrence reads a maximum over three "take" options.

### Approach

Compute a suffix DP where `dp[i]` is the best score difference the player to move can force from stones $i \cdots n-1$, then read off the sign of `dp[0]` (since Alice is starting).

#### Prep

- `dp[i]` = max difference ($\text{current player score} - \text{opponent score}$) from suffix $i \cdots n-1$
- each state only depends on the next three, so a 4-slot ring buffer suffices
- `dp[4]` initialized to all zeros, doubling as the empty-suffix sentinels
- iterate $i$ from $n - 1$ down to $0$, filling later indices first

#### The Logic

- **Difference Recurrence with Running Sum:**  
  `take` accumulates the next $1$, $2$, or $3$ stone values as $k$ grows, so no prefix sum array is needed.  
   After taking $k$ stones worth `take`, the opponent moves and forces $dp[i + k + 1]$ against us.  
   Net edge is `take - dp[i + k + 1]`, so $dp[i]$ is the max over $k = 1, 2, 3$
- **Rolling Ring Buffer:**  
  `dp[i]` reads positions $i+1$, $i+2$, $i+3$, so 4 slot circular buffer overwrites oldest states as $i$ descends.  
  `best` writes to `dp[i % 4]`, replacing the slot used by state $i + 4$
- **Initialization Trap:**  
  `best` starts at $-\infty$ because stone values can be negative, and an empty max would wrongly report zero.

#### Getting the result

- `dp[0]` $> 0$ means Alice wins, `dp[0]` $< 0$ means Bob wins, equality means Tie

---

### Complexity

- **Time Complexity:** $O(n)$
  - each of $n$ positions tries at most 3 take lengths, constant work per state
- **Space Complexity:** $O(1)$
  - rolling buffer holds a fixed 4 slots regardless of input length
