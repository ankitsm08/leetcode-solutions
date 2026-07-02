## Node-Weighted 0-1 BFS over Deque (Dial's Variant)

### Intuition

This is a shortest path problem hidden as a health grid navigation game. Instead of heavy Dijkstra heaps, the costs are strictly binary choices of zero or one. Processing zero-cost cells first guarantees finding the healthiest path layer by layer. We can drop the deque completely and just shuffle between two vectors.

### Approach

Use a two-vector 0-1 BFS to process zero-cost grid cells before dropping health layers.

#### Prep

- flatten the visited tracking into a 1d array for better cache locality
- reduce starting health by the cost of the initial grid cell immediately

#### Logic

- **Double Vector Shuffling:**  
  We swap the current and next layer vectors when the current finishes.
- **Visited on Push Optimization:**  
  Marking nodes visited immediately when pushing prevents duplicate coordinates from bloating vectors.  
  This works because zero-cost cells always exhaustively clear out before any health drop.

#### Getting the result

Return `true` immediately if the destination coordinate is popped from the current layer. If health runs out before hitting the target, return `false`.

---

### Complexity

- **Time Complexity:** $O(m \times n)$
  - process every grid cell exactly once without any heap sorting overhead
- **Space Complexity:** $O(m \times n)$
  - allocated for the visited array and the layer tracking vectors
