## Contiguous Connected Components

### Intuition

We want to find if there is a path between two nodes in a graph where edges only exist between values within a certain difference. Since `nums` is already sorted, we dont need to build a heavy union find structure. That is obviously overkill and too slow.

Any adjacent gap larger than `maxDiff` acts as an absolute barrier. Because the array is sorted, no element from the left of the gap can ever bridge to the right of the gap. This splits the graph into contiguous, completely isolated partitions.

### Approach

We partition the sorted array into contiguous components in a single pass and answer reachability queries in constant time.

#### Prep

- store the component group ID for each index of the array
- track the active integer identifier for the current contiguous group

#### The Logic/Tricks

- **Contiguous Partitioning:**  
  Gaps larger than `maxDiff` split the array into isolated intervals that cant connect
- **Branchless Component IDs:**  
  We increment the component identifier using a comparison result to avoid branch overhead

#### Getting the result

- we verify if the two queried nodes share the same component ID

---

### Complexity

- **Time Complexity:** $O(n + q)$
  - we process the array and answer each queries in $O(1)$
- **Space Complexity:** $O(n)$
