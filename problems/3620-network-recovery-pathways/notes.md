## Binary Search on Answer with Memoized DFS

### Intuition

Checking all paths causes a massive time limit error because graph paths explode exponentially. Instead of hunting for the best path, we flip the problem to just guessing an answer. We guess a score, filter out the weak edges, and see if any valid path still fits the budget.

### Approach

Binary search the maximum score and verify if the shortest path fits the budget using memoized DFS.

#### Prep

- build an adjacency list to speed up the neighbor lookups
- filter out any edges where source or destination is offline
- track the highest edge weight to set binary search ceiling

#### The Logic (Optimizations)

- **Binary Search Guessing:** Guess a minimum edge score and ignore anything smaller in the graph.  
  This turns an exponential pathfinding nightmare into a simple boolean check
- **Memoized DFS Shortest Path:** Run a recursive DFS to find the absolute cheapest route available.  
  Cache answers in a memo array to avoid repeating identical work.  
  This keeps time complexity linear by never processing a node twice

#### Getting the result

Update the best score whenever the DFS finds a valid path under budget. Return the highest score that successfully reached the destination node.

---

### Complexity

- **Time Complexity:** $O((V + E) \log W)$
  - binary search runs log times while dfs processes nodes once
- **Space Complexity:** $O(V + E)$
  - for storing the pruned graph and the memoization state array
