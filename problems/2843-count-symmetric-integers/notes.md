## Compile-Time Precomputation with Binary Search

### Intuition

The range is tiny ($1$ to $10^4$), so we could brute-force every number. But the tight bound means we can also just enumerate every symmetric integer at compile time: only $2$-digit and $4$-digit numbers qualify (odd-digit numbers are never symmetric, and no $6$-digit number fits in $10^4$). That gives at most $624$ candidates, so we can store them in a sorted lookup array and answer each query with two binary searches.

### Approach

Precompute all symmetric integers at compile time via `constexpr`, then use `lower_bound` / `upper_bound` to count how many fall in $[low, high]$.

#### Prep

- only 2-digit and 4-digit numbers can be symmetric within the constraint
- calculate `N` as total number of symmetric numbers withing the constraint
- generate the lookup array at compile time

#### The Tricks

- **Compile-time precomputation:**  
  `constexpr` lambdas run at build time, so the loop and digit-sum logic produce zero runtime cost
- **Two-digit case:**  
  A 2-digit number `i` is symmetric when `i / 10 == i % 10` which gives $11, 22, \dots, 99$
- **Four-digit case:**  
  Extract the four digits via integer division and modulo operators and compare `(d1 + d2) == (d3 + d4)`

#### Getting the result

- `lower_bound` finds the first index $\ge low$, `upper_bound` finds the first index $> high$, their difference is the count

---

### Complexity

- **Time Complexity:** $O(\log N) \approx O(1)$
  - $N$ is constant ($624$), so its effectively $O(1)$
- **Space Complexity:** $O(N) \approx O(1)$
  - the lookup array is statically embedded with no runtime allocation
