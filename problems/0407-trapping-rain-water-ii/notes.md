Work from the outside in. The lowest cell on the boundary is the "bottleneck" that limits the maximum water level for its neighbors.

Push all outer edge cells into a min-heap. Pop the lowest cell, check its unvisited neighbors, and trap water if a neighbor is shorter than the popped cell.

Push the visited neighbor back into the heap using `max(neighbor_height, boundary_height)` as its new boundary height.

---

- **Time complexity:** $O(mn \log{(mn)})$
- **Space complexity:** $O(mn)$
