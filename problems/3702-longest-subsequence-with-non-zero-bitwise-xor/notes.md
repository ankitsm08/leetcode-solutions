## Full-Array XOR Greedy

### Intuition

A subsequence is really just a subset, since XOR ignores order and positions. So we only decide which elements to keep, and the full array is the obvious maximum candidate. If its XOR is non-zero, we keep everything and win with $n$. If the total XOR is zero, dropping exactly one element $x$ rewrites the total from $0$ to $0 \oplus x = x$, so removing any non-zero element leaves a valid subsequence of length $n - 1$. The only dead end is when every element is zero, because then every subsequence XORs to zero.

### Approach

Take all $n$ elements unless the total XOR is zero, then drop a single non-zero element.

#### Prep

- `total_xor` accumulates the XOR of every element in one pass
- `all_zero` ORs all elements to detect any non-zero value
- all-zero input means no valid subsequence exists, so return 0 early

#### The Logic

- **Single Drop Reset:**  
  With total XOR $0$, removing element $x$ leaves $0 \oplus x = x$, which is non-zero for any non-zero $x$; one removal always suffices.
- **Flag as Count:**  
  `!total_xor` maps the zero/non-zero flag to $1$/$0$, so `nums.size() - !total_xor` yields either $n - 1$ or $n$.

#### Getting the result

- guard the all-zero case with the early return 0, then return `nums.size() - !total_xor`

---

### Complexity

- **Time Complexity:** $O(n)$
  - single pass computing both the XOR and the OR
- **Space Complexity:** $O(1)$
  - only two running accumulators