## Greedy with GCD-Shrunk Requirement and Rightmost Digit Bump

### Intuition

The digit product is divisible by $t$ exactly when every prime factor of $t$ shows up among the digit factors. Digits $2..9$ only supply primes $2, 3, 5, 7$, digit $1$ supplies nothing, and digit $0$ is banned. So if $t$ carries any other prime, no zero-free number can ever work and we return $-1$ right away. This gate reduces the whole problem to covering $t$'s $2/3/5/7$-exponents with digits.

We never compute the actual product of digits, since it would overflow after a few digits. Instead we track the leftover requirement as a divisor of $t$: a digit $d$ pays off $\gcd(\text{remaining}, d)$, so the requirement shrinks to $\dfrac{\text{remaining}}{\gcd(\text{remaining}, d)}$. The value is always a divisor of $t$, hence at most $10^{14}$, and fits in a long long.

For the smallest number $\ge num$ we keep the longest possible prefix of $num$ unchanged, bump exactly one digit upward, and squeeze the tail into the lexicographically smallest valid arrangement. If no position can be bumped successfully, every length-$n$ candidate fails, so the answer must be the smallest valid zero-free number of length $n+1$, built by factoring $t$ into digits and padding with $1$s.

### Approach

Gate $t$ on its prime factors, walk the prefix while shrinking `remaining` by gcd, then sweep positions right-to-left bumping a digit and filling the tail with the largest dividing digit; on total failure, emit $t$ factored into digits and padded to length $n+1$.

#### Prep

- strip all powers of 2 via `countr_zero`, then divide out $3, 5, 7$; leftover $\ne 1$ returns `"-1"`
- `remaining[i]` stores the uncovered part of $t$ after the prefix `num[0..i-1]`
- `GCD[a][b]` precomputes $\gcd(a, b)$ for $b < a$ in a constexpr lambda
- `pos` points at the first zero in `num`, the rightmost position we may raise

#### The Logic and Tricks

- **Requirement Shrink by GCD:**
  - **Gcd overlap:**  
    Digit $d$ at position $i$ covers $\gcd(\text{remaining}\texttt{[i]}, d)$, so $\text{remaining}\texttt{[i+1]} = \dfrac{\text{remaining}\texttt{[i]}}{\gcd(\text{remaining}\texttt{[i]}, d)}$  
    Digit $1$ covers nothing and `remaining` stays put, so the value never grows past $t$
  - **Modulo table lookup:**  
    Since $\gcd(d, x) = \gcd(d, x \bmod d)$, the read `GCD[d][remaining[i] % d]` returns the overlap with only an index and no big arithmetic.  
    The table only fills the $j < i$ triangle, which the remainder always lands in

- **Rightmost-Change Sweep:**
  - **Longest prefix wins:**  
    A number that matches `num` on a longer prefix is always smaller, so we scan $i$ from `pos` down to $0$ and try every digit above `num[i]`  
    The first $i$ whose tail fills returns, sweeping downward guarantees the earliest prefix is chosen first
  - **Zero forces the bump:**  
    A zero in `num` cannot survive, so the prefix loop stops at the first one and `pos` becomes that index.  
    The greedy starts by raising that zero to $1..9$, and only falls back to earlier positions if none fit
  - **Free skip at `'9'`:**  
    Positions locked at `'9'` contribute no candidates, since `++num[i]` jumps straight past `'9'`, keeping the sweep near-linear in practice

- **Largest-Divisor Suffix Fill:**
  - **Exact-tail greedy:**  
    After bumping `num[i]` to $d$, `curr` $= \dfrac{\text{remaining}\texttt{[i]}}{\gcd(\text{remaining}\texttt{[i]}, d)}$ is what the tail must cover.  
    Walk $j$ from the right, placing the biggest $k \le 9$ that divides `curr`, with $k$ starting at $9$ and only shrinking.  
    Each placed digit divides the current `curr`, so success means the tail product hits exactly $1$
  - **Why descending $k$ is minimal:**  
    Because $k$ never climbs, the suffix reads ascending left-to-right, which is the smallest ordering for any fixed digit multiset.  
    Putting the biggest divisor at the least significant spot leaves the smallest leftover for the more significant digits.  
    Example: covering $64$ with three positions yields $(1,8,8)$ -> `"188"`, beating `248` and `444`

- **Length $n+1$ Fallback:**
  - **Digits cover all of $t$:**  
    Any divisor of $t$ with primes $2,3,5,7$ is a product of single-prime digits, so a valid tail always exists once there are enough positions.  
    The exhausted sweep proves no length-$n$ candidate works
  - **Greedy factorization:**  
    Factor $t$ into digits $9$ down to $2$, largest first to minimize the digit count, laying them right-to-left so they read ascending.  
    Pad the front with $1$s up to $n+1$ positions; a factorization longer than $n+1$ simply stays longer

#### Getting the result

- return `num` itself when the prefix finishes without a zero and `remaining[n] == 1`
- the first successful bump rewrites `num` in place and returns it
- only when every position fails does the padded factorization of $t$ come out

---

### Complexity

- **Time Complexity:** $O(n \log t)$
  - the gate, prefix walk, and fallback factorization each cost $O(n)$ or less
  - each fill attempt walks the whole tail, so the count of fills decides the cost; a fill never fails once the tail reaches the prime-factor count $\Omega(t)$ of $t$: each digit placed strips at least one prime factor off `curr`
  - $\Omega(t) \le 46$ for $t \le 10^{14}$, since $2^{46} \le 10^{14} < 2^{47}$
  - short tails exist only at the rightmost $\Omega(t)$ positions, each trying at most 9 bump digits, so the sweep runs $O(9 \cdot \Omega(t)) = O(\log t)$ failing fills, a cap independent of $n$
  - a long tail succeeds on its first digit, so the sweep never degrades to $O(n^2)$
- **Space Complexity:** $O(n)$
  - `remaining` and `ans` grow linearly with input length
