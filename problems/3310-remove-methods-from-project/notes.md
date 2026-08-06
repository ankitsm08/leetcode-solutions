## Reachability via Iterative Stack DFS

### Intuition

The suspicious set is exactly the transitive closure of method $k$'s outgoing calls, so the problem is pure reachability from a single source. Removal is only legal when no edge crosses from a non-suspicious method into a suspicious one, which turns into a single scan over the input after the traversal.

### Approach

Run an iterative DFS from $k$ over a flat linked-list adjacency, then scan `invocations` once for an incoming cross edge before keeping the non-suspicious remainder.

#### Prep

- `head[u]` stores the pool index of u's first outgoing edge, or $-1$
- `edges` keeps every edge as `{to, next}` in one flat contiguous array
- `visited` marks suspicious methods; `dfs_stack` drives the explicit DFS
- `addEdge` prepends to each node's chain so insertion stays $O(1)$

#### The Tricks

- **Simulated Pointer Adjacency:**  
  `head` acts as list heads while `next` fields are pool indices, not pointers.  
  Avoids $n$ separate heap allocations and keeps traversal cache-friendly

- **Early Mark on Push:**  
  Mark methods visited when they enter the stack so no duplicate ever waits inside.  
  This saves revisiting edges and keeps the traversal at $O(n + E)$ total

- **Deferred Detection Scan:**  
  Do not bookkeep incoming counts during DFS; the outside invoker check is a second $O(E)$ pass over `invocations` with a simple cross-edge test

#### Getting the result

- if any edge has an unvisited source and a visited target, return all $n$ methods
- otherwise collect every method with `visited` false and return it

---

### Complexity

- **Time Complexity:** $O(n + E)$
  - edge building, traversal, and the detection scan are each linear passes
- **Space Complexity:** $O(n + E)$
  - `head`, the `edges` pool, `visited`, and the DFS stack all scale linearly
