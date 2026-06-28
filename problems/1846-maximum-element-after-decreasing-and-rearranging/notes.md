## Greedy + Frequency Buckets

### Intuition

Since we can reorder freely and only **decrease** values, the best possible array is basically `1, 2, 3, ...` growing as much as allowed by the counts. Big numbers don't matter beyond `n`.

### Approach

Clamp values, count frequencies, then greedily extend the max height step-by-step.

#### Prep

- `count[x]` = how many elements can act as value `x` (after clamping)
- clamp everything to `n` since anything bigger is useless
- start with `ans = 1` because the first element must be `1`

#### Logic

- **Clamping Trick:**  
  Values `> n` are capped to `n`, you can never build a valid sequence taller than length.  
  Saves space and avoids pointless large values

- **Greedy Growth:**  
  At each value `num`, we try to grow `ans` using `count[num]`.  
  But growth is capped by `num` itself since we cannot increase value of any number,  
  this enforces `abs(diff) <= 1` implicitly

#### Getting the result

- `ans` always tracks the largest possible value reachable so far

---

### Complexity

- **Time Complexity:** $O(n)$
  - single pass over the frequency array
- **Space Complexity:** $O(n)$
  - frequency array up to `n`
