## Multi-source BFS with Modified Dijkstra or Binary Search

### Intuition

First figure out how safe every single cell actually is. Then pathfind through the grid maximizing that minimum safeness bottleneck.

### Approach

Precompute thief distances with multi-source BFS and then find the bottleneck path using either Dijkstra or Binary search.

#### Prep

- flatten the 2d grid into a 1d array to boost cache hits
- push all cells with thieves into a queue with zero distance
- run standard multi-source bfs to populate distance for every cell

#### Logic

- **Max-Heap Bottleneck (Dijkstra):**  
  Run dijkstra but maximize the minimum safeness seen along the path.  
  Keeps track of the best bottleneck distance to reach each cell

- **Smart Search Space (Binary Search):**  
  The answer cannot exceed the safeness of the start or end cell.  
  Cap the binary search high bound to save useless iterations
- **Threshold BFS (Binary Search):**  
  Guess a minimum safeness factor and run a standard bfs.  
  Only step on cells having safeness greater than or equal to mid

#### Getting the result

For dijkstra, just return the safeness factor when you pop the destination cell.  
For binary search, return the highest valid mid that successfully reached the end.

---

### Complexity

- **Time Complexity:** $O(n^2 \log n)$
  - heap operations or binary search runs add logarithmic factor over grid size
- **Space Complexity:** $O(n^2)$
  - for the flattened safeness array and queue structures
