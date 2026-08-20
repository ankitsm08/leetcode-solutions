## Counting Even-Product Compositions

### Intuition

A sequence of $k$ positive integers summing to $n$ is a composition of $n$ into $k$ parts. Even product means at least one part is even. Counting "at least one even" directly means inclusion-exclusion over which parts are even, which gets messy. Flip it instead: count every composition, then subtract the bad ones (all parts odd). The all-odd subset has a clean closed form, so the whole problem reduces to two binomial counts.

### Approach

Count all compositions via stars and bars, then subtract the all-odd compositions when their parity makes them possible.

#### Prep

- an ordered $k$-tuple of positives summing to $n$ is a composition, counted by stars and bars
- number of compositions is $C(n-1, k-1)$, so we only need fast binomials
- binomials live mod $p = 10^9 + 7$, a prime, so division requires modular inverses
- precompute `fact` and `inv_fact` arrays once up to $\max(k)$
- `nCr(n, r) = fact[n] * inv_fact[r] * inv_fact[n - r]` is then $O(1)$

#### The Logic

- **Stars and Bars:**  
  To split $n$ indistinguishable stars into $k$ nonempty groups, drop $k-1$ bars into the $n-1$ gaps between stars (never at the ends, never adjacent).  
  Each choice of $k-1$ gaps is one composition, giving $\binom{n-1}{k-1}$. For $n=5$, $k=3$ that is $\binom{4}{2}=6$, matching the statement
- **Parity Inversion:**  
  Even product is the complement of all-odd, so we count all compositions and subtract the all-odd ones instead of counting the good ones directly
- **All-Odd Transform:**  
  Write each odd part as $2x_i + 1$ with $x_i \ge 0$  
  The sum collapses to $2\sum x_i + k = n$, so $\sum x_i = \dfrac{n-k}{2}$  
  All-odd compositions are then nonnegative solutions to that sum, which by nonnegative stars and bars count as $\dbinom{\frac{(n-k)}{2} + k - 1}{k - 1}$
- **Parity Gate:**  
  The all-odd transform only works when $n-k$ is even.  
  When $n-k$ is odd, no all-odd composition exists, so the answer is just the `total`
- **Fermat Inversion:**  
  Division mod a prime $p$ becomes multiplication by the modular inverse.  
  By Fermat's little theorem $a^{p-1} \equiv 1 \mod p$, so $a^{-1} \equiv a^{p-2} \mod p$,  
  we invert only the largest factorial with binary exponentiation
- **Inverse Factorial Cascade:**  
  Since $(i-1)! = \dfrac{i!}{i}$, taking inverses flips the division into multiplication and gives $\text{inv}_{i-1} = i \cdot \text{inv}_{i}$  
  One Fermat seed plus $O(k)$ multiplications fills the rest, which is why we never run FLT per element

#### Getting the result

- `total = C(n - 1, k - 1)` counts every composition
- `odd = C((n - k) / 2 + k - 1, k - 1)` counts the all-odd ones when $n-k$ is even
- answer is $(\text{total} - \text{odd}) \mod \text{p}$

---

### Complexity

- **Time Complexity:** $O(k)$
  - factorial build plus inverse-factorial cascade is two linear passes
  - single binary exponentiation is $O(\log p)$, effectively constant
- **Space Complexity:** $O(k)$
  - `fact` and `inv_fact` each hold $k$ ints
