## Inclusion-Exclusion GCD with Loop Fusion

### Intuition

Generating $O(n^2)$ pairs is obviously a dead end. Instead of counting pairs directly, we can count multiples. If we know how many elements are multiples of $x$, picking any 2 of them guarantees their GCD is at least $x$. From there, we just strip away the pairs that have an exact GCD of $2x, 3x, \dots$ to find the pairs with an exact GCD of $x$.

### Approach

Count element frequencies, then iterate backwards to simultaneously calculate pairs of multiples and subtract overlapping exact GCDs using inclusion-exclusion.

#### Prep

- `numCount[x]` stores the frequency of value $x$ in the input array
- `gcdArr[i]` stores the exact number of pairs whose GCD is exactly $i$
- find the max element `mx` to tightly bound our loops and array operations

#### The Tricks

- **Backwards Inclusion-Exclusion:**  
  Normally we would need one loop to count pairs of multiples and another one to subtract exact counts of larger multiples.  
  By iterating backwards from `mx` down to $1$, the exact counts for larger multiples are already finalized, letting us subtract them instantly
- **Loop Fusion and State Recycling:**  
  Inside the loop for $i$, we iterate through its multiples ($j = i,\, 2i,\, 3i, \dots$) and tally the total elements that are multiples (`count += numCount[j]`),  
  while simultaneously tallying the overlapping exact pairs (`extra += gcdArr[j]`)  
  Then `gcdArr[i]` is just `(count * (count - 1) / 2) - extra`  
  Setting `gcdArr[i] = 0` before the inner loop resets value from previous test case
- **In-Place Prefix Sums:**  
  Run `std::partial_sum` directly on `gcdArr` to transform it from exact counts into a prefix sum array, requiring zero extra memory allocations

#### Getting the result

- for each query, use `std::upper_bound` on the prefix summed `gcdArr` to find the first index where the running total exceeds the query index
- the iterator distance from the start is the exact GCD value
- clean up `numCount` using `std::fill` so the global state is ready for the next testcase

---

### Complexity

- **Time Complexity:** $O(n + m \log m + q \log m)$
  - $O(n)$ to count frequencies and find max
  - harmonic series loop takes $O(m \log m)$ where $m$ is `mx`
  - $O(q \log m)$ to answer $q$ queries via binary search
- **Space Complexity:** $O(m)$
  - only two static arrays of max of numbers `mx`
