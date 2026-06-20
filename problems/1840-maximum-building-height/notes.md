Convert all restrictions into tight upper bounds, then compute the max peak between every adjacent restriction pair.

- height difference between adjacent buildings `<= 1` ==> slope constraint
- treat restrictions as fixed "anchor points"; add `(1, 0)` and `(n, +inf)` as sentinels to close the left and right side
- sort and do a forward and backward pass to find maximal feasible heights, clamping each height by adjacent + distance
- between two anchors `(x1, h1)` and `(x2, h2)`, tallest peak is where slopes meet
- max over all (peak height = $\dfrac{h_1 + h_2 + (x_2 − x_1)}{2}$) is the answer.

### Notes:

- **Integer Overflow:** Calculation of peak height must be forced into `long long` (e.g., `0LL + ...`) to avoid 32-bit integer overflow
- **Memory Locality & CPU Cache:**
  - LeetCode provides the input as `vector<vector<int>>`
  - because `vector<int>` has a 24-byte manager overhead and allocates data randomly on the heap, iterating through it causes constant CPU cache misses
  - copying the data into a contiguous `vector<pair<int, int>>` (8 bytes per element) makes sorting and looping **drastically faster**

---

- **Time Complexity:** $O(k \log k)$
  - where `k` = size of restrictions; sorting is the only expensive operation here
- **Space Complexity:** $O(k)$
  - I store the restrictions in a new vector of pairs to optimize CPU cache locality and execution speed
  - without this, I was getting triple the amount of time in submissions (but this does come at a cost of increased memory usage)
