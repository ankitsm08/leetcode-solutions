## Bitset State Compression & Chain Simulation

### Intuition

The pattern is basically a symmetric mountain built on repeated squaring: `x, x^2, x^4 ... x^k ... x^4, x^2, x`. Because squaring grows ridiculously fast, chains are super short (at most 5 steps). We can just simulate the chain from every possible base. The bottleneck here is the `unordered_map` overhead. Dropping heap-allocated maps for flat bitsets gives a massive speedup.

### Approach

We compress frequencies into tiny, L1-cache-friendly bitsets by bounding the max possible mountain base to $\sqrt{10^9}$, and simulate the squaring climb for any base that has at least two copies.

#### Prep

- `freq1` and `freq2` act as a 3-state counter (0, 1, or 2+ copies) for numbers up to `31622`
- `sqrset` tracks huge numbers (`> 31622`) that can only act as the single peak. Store them by marking their square roots
- track `minNum` and `maxNum` during the first pass so we don't iterate over empty bitset space later

#### Optimizations

- **The $\sqrt{10^9}$ Boundary:**  
  The max value in `nums` is $10^9$. Since $31622^2 \approx 10^9$, any number $> 31622$ squared will overflow the problem limits. This means large numbers can _only_ be peaks, not bases.  
  We don't need a large map to count them; just check if they are perfect squares and flag in `sqrset`.  
  This drops space complexity from $O(N)$ to $O(\sqrt{\max(nums)})$
- **Pruning Unviable Bases:**  
  Instantly skip numbers that don't have at least 2 copies. A valid sequence needs a left and right side, so if we only have 1 copy, it's a dead end
- **Edge Case for `1`:**  
  The number `1` loops infinitely if squared, so we handle it upfront

#### Getting the result

For every valid base, we simulate squaring to climb the chain. As soon as the count drops below 2, the loop breaks. We tack on the peak (if it exists) using `2 * (len + count) - 1` and track the absolute max length found.

---

### Complexity

- **Time Complexity:** $O(N)$
  - building the bitsets takes one pass.
  - the squaring simulation runs at most $\sim 5$ times per unique base ($O(1)$)
- **Space Complexity:** $O(\sqrt{\max(nums)})$
  - 3 bitsets of size `31623` take about `12 KB` in total, perfectly inside the CPU's fastest L1 cache
