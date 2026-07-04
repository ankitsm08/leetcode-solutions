## Disjoint Set Union (Union-Find) or Component Traversal (Stack DFS)

### Intuition

Because the problem allows us to cross any road or visit any city an infinite number of times, we do not need to track a specific direct path from city $1$ to city $n$. We just need to find the absolute smallest edge weight anywhere inside the entire connected component containing city $1$. The problem shifts from pathfinding to simply identifying which edges belong to our component and grabbing the minimum.

### Approach

Identify the connected component containing city $1$ either by merging nodes into disjoint sets with flat arrays, or by explicitly traversing the graph using an iterative stack.

#### Prep

- **For Stack DFS:**  
  Build a bidirectional adjacency list, and allocate a `visited` boolean array.
- **For Union-Find:**  
  Initialize flat 1D `parent` and `size` tracking arrays.  
  Make every node its own boss initially, completely bypassing adjacency list allocation.

#### Logic

- **Iterative Stack DFS:**
  - **Component Edge Relaxation:**  
    Manually push unvisited neighbors onto the stack.  
    Every time an edge is traversed, update the global minimum.
  - **Early Visited Marking:**  
    Mark nodes as visited during the stack push phase rather than the pop phase to instantly block duplicate nodes from entering the container.

- **Disjoint Set Union (Union-Find):**
  - **Path Compression & Union by Size:**  
    Flatten the lookup trees during the find phase by pointing nodes directly to the ultimate root boss.  
    Always merge the smaller component under the larger root to keep the structures balanced.

#### Getting the result

- **For Stack DFS:**  
  Allow the stack to completely exhaust the component.  
  Return the final global minimum score recorded across all visited edges.
- **For Union-Find:**  
  Grab the root boss of city $1$. Loop through the raw input `roads` array one last time.  
  If an edge's source city belongs to that same boss, check its weight against your running minimum.

---

### Complexity

- **Time Complexity:**
  - Union-Find: $O(E \cdot \alpha(V))$
    - where $\alpha$ is the "Inverse Ackermann" function, making edge grouping effectively $O(1)$
  - Stack DFS: $O(V + E)$
    - linear time to touch every reachable node and edge exactly once
- **Space Complexity:**
  - Union-Find: $O(V)$
    - requires only two flat 1D tracking arrays
  - Stack DFS: $O(V + E)$
    - stores the adjacency list and the stack
