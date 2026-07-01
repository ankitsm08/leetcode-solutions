## Multi-source BFS with Dial's Algorithm, Modified Dijkstra, or Binary Search

### Intuition

We cant evaluate any path without knowing where the danger is first. Expanding outward from all thieves at once gives us a heat map of safeness for every cell. Once we have this grid of distances, the problem changes entirely. It becomes a game of pathfinding where we want to avoid stepping on low numbers. We can either greedily pick the safest available route, guess a bottleneck threshold and verify it, or walk down safeness levels one by one.

### Approach

Precompute thief distances with multi-source BFS and then find the bottleneck path using Dial's algorithm, Dijkstra, or Binary search.

#### Prep

- flatten the 2d grid into a 1d array to boost cache hits
- push all cells with thieves into a queue with zero distance
- run standard multi-source bfs to populate distance for every cell

#### Logic

- **Binary Search:**
  - **Smart Search Space:**  
    The answer cannot exceed the safeness of the start or end cell.  
    Cap the binary search high bound to save useless iterations
  - **Threshold BFS:**  
    Guess a minimum safeness factor and run a standard bfs.  
    Only step on cells having safeness greater than or equal to mid

- **Dijkstra's Algorithm (Max-Heap Bottleneck):**  
  Run dijkstra but maximize the minimum safeness seen along the path.  
  Keeps track of the best bottleneck distance to reach each cell

- **Dial's Algorithm (2-Queue BFS):**  
  Drop the heap overhead since adjacent cell safeness differs by at most 1,  
  use two arrays to process current threshold and queue the next threshold.  
  This drops the time complexity by a factor of $O(\log n)$

#### Getting the result

For dial's algorithm, just return the threshold answer when you reach the end.  
For dijkstra, return the safeness factor when you pop the destination cell.  
For binary search, return the highest valid mid that successfully reached the end.

---

### Complexity

- **Time Complexity:**
  - Dial's Algorithm: $O(n^2)$
    - avoids the $O(\log n)$ overhead by removing the priority queue
  - Dijkstra or Binary Search: $O(n^2 \log n)$
    - heap operations or binary search runs add logarithmic factor over grid size
- **Space Complexity:** $O(n^2)$
  - for the flattened safeness array and queue structures
