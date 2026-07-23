## Bitwise Basis Span for XOR Triplets

### Intuition

When we pick three elements $a$, $b$, $c$ from a permutation of $1$ to $n$, setting two indices equal gives $a \oplus a \oplus c = c$. This trivially gives us every number from $1$ to $n$ for free.

For $n >= 3$, we have enough numbers in $[1, n]$ to span every single bit pattern up to the most significant bit of $n$. Three elements give us enough degrees of freedom to toggle bits arbitrarily, so we fill the entire range from $0$ up to the next power of $2$.

### Approach

Return $n$ for $n <= 2$, otherwise return the smallest power of $2$ strictly greater than $n$ using a single CLZ instruction.

#### Prep

- $n$ represents array length and maximum available integer
- $k$ represents bit position of most significant bit of $n$

#### The Logic

- **Self Canceling Pair:**  
  Setting $i = j$ reduces $a \oplus a \oplus c$ to $c$, giving every integer in $[1, n]$ directly
- **Zero Formation:**  
  Using $1 \oplus 2 \oplus 3 = 0$ handles $0$ since $n >= 3$ guarantees $1$, $2$, $3$ exist
- **Full Range Span:**  
  Combining $2^k$ with pairs from $[1, n]$ generates all numbers up to $2^{(k + 1)} - 1$
- **Bitwise Logarithm:**  
  Using `31 - __builtin_clz(n)` computes $\text{floor}(\text{log2}(n))$ in a single hardware cycle

#### Getting the result

- return $n$ for $n \le 2$, else return $2^{k + 1}$

---

### Complexity

- **Time Complexity:** $O(1)$
  - constant time calculation using hardware clz instruction
- **Space Complexity:** $O(1)$
