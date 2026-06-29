## Combinatorics (Binomial Coefficient)

### Intuition

Since each path is unique and formed by different permutation of the down and right move choices, we have exactly `m - 1` downs and `n - 1` right choices to make. The permutation of these choices give us the path. So we count total permutations (arrangements).

### Approach

The answer is simply $\dbinom{n}{r} = P(n, r) = \dfrac{n!}{(n-r)!}$

#### Prep

- Set k to smaller of `m - 1` or `n - 1` to minimize loop
- Start ans at 1 as `long long` to handle large intermediates
- Total steps always `m + n - 2`

#### Avoiding Overflow

- **Incremental binomial:**  
  Multiply by next numerator then divide by i in loop.  
  Keeps numbers small and exact due to integer division order

- **Symmetry trick:**  
  Only compute up to `min(m - 1, n - 1)` since $\dbinom{m + n - 2}{m - 1} = \dbinom{m + n - 2}{n - 1}$.  
  Cuts iterations in half for unbalanced grids

---

### Complexity

- **Time Complexity:** $O(\min(m,n))$
- **Space Complexity:** $O(1)$
