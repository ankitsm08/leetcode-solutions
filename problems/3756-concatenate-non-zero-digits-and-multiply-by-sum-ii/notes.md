## Prefix Sum and Modular Digit Shifting

### Intuition

We need to find the product of the active digits and their sum for each substring. The string is too long to construct the numbers directly, so we dont want to evaluate them naively.

Instead of building each number from scratch, we can extract any substring using a mathematical shift. Subtracting the left prefix from the right prefix requires shifting the left prefix by the number of active digits in the range. By keeping everything modulo $\text{MOD}$, the math stays within standard integer bounds and doesnt overflow.

### Approach

Build prefix arrays for sums, non-zero digit concatenations, and active counts to evaluate queries in constant time via modular subtraction.

#### Prep

- `sumPrefix` tracks the prefix sum of all digits for $O(1)$ range sum queries
- `digitPrefix` stores the concatenated non-zero digits modulo `MOD` up to each index
- `numLen` tracks the count of non-zero digits up to each index for determining the shift power
- `pow10` contains precomputed powers of 10 modulo `MOD` to prevent manual recalculations

#### The Logic and Tricks

- **Modular Substring Extraction:**  
  `digitPrefix[i]` holds the number formed by all non-zero digits up to `i - 1`, modulo `MOD`.  
  If the string were `"10203"`, then `digitPrefix[5]` would be the modular representation of `123`.  
  To extract the substring number for range `[l, r)`, we only need the left prefix `L = digitPrefix[l]` and the right prefix `R = digitPrefix[r]`.

  The substring number `subNum` satisfies:

  $$R = L \cdot 10^{\text{subLen}} + \text{subNum}$$

  Rearranging and applying the modulus:

  $$\text{subNum} = \left(R - (L \cdot 10^{\text{subLen}} \bmod \text{MOD}) + \text{MOD}\right) \bmod \text{MOD}$$

  `subLen` is the count of non-zero digits in `[l, r)`, computed as `numLen[r] - numLen[l]`.  
  This works because zero digits contribute nothing to the concatenated value and dont affect the shift length

- **IIFE Static Precomputation:**  
  `inline static` makes `pow10` shared across all test cases without recomputation, and  
  the IIFE guarantees the array is populated before any call to `sumAndMultiply`

#### Getting the result

- `subNum * (sumPrefix[r] - sumPrefix[l]) % MOD` gives the final answer for each query

---

### Complexity

- **Time Complexity:** $O(n + q)$
  - processing the string once and then each query is evaluated in $O(1)$ time
- **Space Complexity:** $O(n + M)$
  - we store prefix arrays of size $n$ and a static array of size $M$
