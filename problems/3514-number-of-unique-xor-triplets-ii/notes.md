## Compress and Convolve

### Intuition

We need distinct values of $a \oplus b \oplus c$ where $a, b, c$ are elements of `nums` (indices can repeat). The naive $O(n^3)$ is too slow for $n \le 1500$, but the values themselves are tightly bounded ($nums[i] \le 1500$). So the number of _unique_ values we can produce is also bounded by the XOR closure of a small set.

### Approach

Squash duplicates, enumerate all unique pair XORs via boolean array, then combine with each unique element to produce triplet XORs.

Let $M = \text{max}$ and $X = \text{XOR}_\text{max}$.

#### Prep

- `unique_nums` marks which values actually appear in `nums` (size $M + 1$)
- `unique_pair_xors` marks reachable XORs of two elements (size $X + 1$)
- $X$ is the largest value representable with the same bit length as $M$ ($2^{\lfloor \log_2 M \rfloor + 1} - 1$)

#### The Logic

- **Duplicates dont matter:**  
  Since we only care about _unique_ XOR values, we work with the set of distinct numbers.  
  The bound on $nums[i]$ means we use a flat boolean array instead of a hash set, giving $O(1)$ lookup and reset

- **Pair XORs by enumeration:**  
  Iterate $i \le j$ over the value range $[0, M]$ where both values exist. Mark $i \oplus j$ in `unique_pair_xors`  
  This is $O(M^2)$, but $M \le 1500$. Seed $0$ as reachable ($x \oplus x = 0$)

- **Triplet XORs by convolution:**  
  For each existing value $i$, XOR it with every reachable pair XOR $j$ and mark $i \oplus j$ in `unique_triplet_xors`  
  This is $O(M \cdot X)$ where $X \le 2047$

#### Getting the result

- count the number of `true` entries in `unique_triplet_xors` up to $X$

---

### Complexity

- **Time Complexity:** $O(M^2 + M \cdot X)$
- **Space Complexity:** $O(M + X)$
