## Binary Lifting on Contiguous Components

### Intuition

Edges connect nodes whose values differ by at most `maxDiff`. Sorting by value turns the graph into a line where each node can reach a contiguous suffix. The shortest path from `L` to `R` is just the minimum number of greedy rightmost jumps to go from the lower position to the higher one. Gaps larger than `maxDiff` split the array into independent components.

### Approach

Precompute a sparse table of jump targets so each query can be answered in $O(\log n)$ time using binary lifting.

#### Prep

- `nodes` stores the sorted values alongside their original indices for range queries
- `orig` maps original node indices back to their sorted positions in our array
- `component` partitions the array into disconnected groups so we skip unreachable queries instantly
- `Bl` is a flat $O(n \log n)$ array indexed by `k * MAXN + idx` holding the sparse table

#### The Logic and Tricks

- **Greedy Base:**  
  For each sorted position `i`, scan right to find the farthest index reachable in one jump. Jumping as far right as possible never hurts cuz any node before that point is also reachable in one step, so the rightmost option always dominates.
- **Sparse Table Recurrence:**  
  `jump[i][k] = jump[ jump[i][k-1] ][k-1]`.  
  Jumping $2^k$ steps is just two jumps of $2^{k-1}$ each.  
  We compute this for $k$ up to $\lceil \log_2 n \rceil$, building each layer from the previous one.
- **Query with Binary Lifting:**  
  Starting from `L`, iterate $k$ from largest to smallest. If `jump[L][k] < R`, take it. It advances us maximally without overshooting.  
  After exhausting all $k$, one more single jump lands at or past `R`, giving the total step count as `steps + 1`.
- **Static 1D Flattening:**  
  We flatten the jump table into a 1D `array` indexed as `k * MAXN + idx` so the entire structure sits in static memory with contiguous cache-friendly layout
- **Disjoint Component Skipping:**  
  Component ID comparison filters disconnected queries in $O(1)$ before any binary lifting loop runs

#### Getting the result

- mismatched component ids means the nodes are in different components, answer is `-1`
- same position costs `0`
- binary lifting on the sparse table gives the minimum steps, `+1` for the final landing jump

---

### Complexity

- **Time Complexity:** $O((n + q) \log n)$
  - sorting and building the sparse table dominate initialization
  - each query runs in $O(\log n)$ or dismissed in $O(1)$
- **Space Complexity:** $O(n \log n)$
  - the static table stores $n \cdot \lceil \log_2 n \rceil$ integers
