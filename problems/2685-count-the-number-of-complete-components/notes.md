## Disjoint Set Union and Complete Component Counting

### Intuition

We want to find how many connected components are complete graphs. A standard DFS or BFS works, but we dont want to build a heavy adjacency list because it takes unnecessary memory. We can bypass graph allocation completely using a disjoint set union.

A component is complete if and only if every node connects to every other node in it. For a component with $v$ vertices, this requires exactly $\dfrac{v (v - 1)}{2}$ edges. By tracking the vertex counts and edge counts for each subset, we can verify completeness directly.

### Approach

We use a disjoint set union to group vertices and count edges per component, then verify mathematical completeness for each root.

#### Prep

- `parent` tracks the parent pointer of each node to find subset roots
- `sz` maintains the number of vertices in each disjoint set component
- `edge_count` stores the total number of unique edges inside each component

#### The Tricks

- **Algebraic Completeness Check:**  
  A component of size $v$ must have exactly $\dfrac{v (v - 1)}{2}$ edges to be complete
- **Flat Array Edge Counting:**  
  We map edges to their component roots using a fast post-processing pass
- **Bitwise Division Optimization:**  
  We use a bitwise right shift instead of division to compute the edge limit

#### Getting the result

- we increment the result if the root size and edge counts match perfectly

---

### Complexity

- **Time Complexity:** $O(n + e \cdot \alpha(n))$
  - the components are processed in near-linear time using path compression
- **Space Complexity:** $O(n)$
  - simple flat arrays without building adjacency lists
