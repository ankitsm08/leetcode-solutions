## Range Max Query on Zero-Block Pairs

### Intuition

A trade sacrifices a '1' block (turns to '0') then converts a '0' block (turns to '1'). The sacrificed '1' must be surrounded by '0's to be eligible for step 1. Turning it to '0' merges the two adjacent zero blocks. After merging, the combined block is bounded by '1's (or the augmented sentinel '1's), making it eligible for step 2. The sacrificed '1' does a round-trip (1->0->1) so it contributes nothing to the net gain. The gain is simply the sum of the two merged zero blocks.

### Approach

Decompose the string into zero blocks, represent each adjacent pair by the sum of their lengths, and answer each query by finding the maximum pair sum intersecting the query range.

#### Prep

- `blocks` stores `[start, end]` for every maximal '0' segment in `s`
- `pair_sums[i] = len(blocks[i]) + len(blocks[i+1])` for $i \in [0, m - 2]$
- sparse table over `pair_sums` for $O(1)$ range maximum queries
- `prev_zero[i]` and `next_zero[i]` map each position to the nearest zero-block index to its left/right (or -1 if none)

#### Logic and Tricks

- **Sentinel Augmentation:**  
  The problem treats each substring as `'1' + s[l..r] + '1'`  
  This guarantees the outermost zero block in the range is always bounded by '1's after step 1, so it can always be converted in step 2.  
  It also ensures the zero block pair at the query edges is a valid candidate
- **Block-Pair Gain:**  
  Merging two adjacent zero blocks by sacrificing the '1' between them yields net gain = `len(block_i) + len(block_{i+1})`  
  The sacrificed '1' block is inside the merged region, so it goes 1->0->1 and cancels out
- **O(1) Edge Block Lookup:**  
  For a query `[l, r]`, the first intersecting zero block is `next_zero[l]` and the last is `prev_zero[r]`  
  `next_zero` for a '1' points to the first zero block at or after it; for a '0' points to its own block.  
  `prev_zero` mirrors this from the left.  
  This replaces a while-loop scan with a direct array lookup
- **Edge Trimming:**  
  For queries that partially slice the first or last block of a pair, use `trim_len` instead of full block length.  
  The trimmed length is the intersection of the block with `[l, r]`
- **Three-Region Candidate:**  
  With 3+ blocks, the best pair is the max of:
  - left edge: `trim(first) + full(second)`
  - right edge: `full(second_last) + trim(last)`
  - middle: range max query over `pair_sums[first_idx+1 .. last_idx-2]`  
    (all interior pairs are fully inside the range)
- **Sparse Table:**  
  Sparse table gives $O(1)$ RMQ on the $m − 1$ pair sums, allowing each query to run in strictly $O(1)$ time after $O(n)$ preprocessing

#### Getting the result

- 0 or 1 block intersecting the range -> no valid trade, return `total_ones`
- 2 adjacent blocks -> `total_ones + trim(first) + trim(last)`
- 3+ blocks -> `total_ones + max(left_edge, right_edge, middle)`

---

### Complexity

For $m \leq \left\lceil \dfrac{n}{2} \right\rceil$ blocks:

- **Time Complexity:** $O(n + m \log m + q)$
  - linear scan for edge blocks and counting 1s takes $O(n)$
  - building blocks and sparse table takes $O(m \log m) \subseteq O(n \log n)$ in the worst case
  - each query needs $O(1)$ for edge block lookup and $O(1)$ for the sparse table lookup
- **Space Complexity:** $O(n + m \log m)$
  - `blocks`, `prev_zero`, `next_zero`, `pair_sums` are all $O(n)$
  - sparse table uses $O(m \log m) \subseteq O(n \log n)$ in the worst case
