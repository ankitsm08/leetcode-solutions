## Memoized Depth via Parent Jumps

### Intuition

We only have the parent of each node, no children lists. But depth is defined purely from the root down, so each node's depth is exactly its parent's depth plus one. That turns depth into a recurrence we can resolve with memoized jumps up the parent chain, no graph building needed.

### Approach

Resolve every depth by walking up parents with memoization, find the tree height, then sum the per-node weights in one pass.

#### Prep

- `depths[i]` holds the depth of node $i$, initialized to $-1$ as unset
- `depths[0] = 1` and clamp `parent[0] = 0` as the base anchor

#### The Logic

- **Memoized Parent Climb:**  
  Depth of $i$ is simply `depths[parent[i]] + 1`  
  The recursive lambda caches results, so a chain of $k$ nodes only does $O(k)$ total work instead of recomputing from scratch
- **Anchor Before Traversal:**  
  Root at depth $1$ seeded upfront.  
  Clamping `parent[0]` to itself stops the climb from hitting the sentinel $-1$

#### Getting the result

- height is the max over all depths
- calculate each node's contribution and return the sum

---

### Complexity

- **Time Complexity:** $O(n)$
  - each depth computed once via memoization, plus two linear passes
- **Space Complexity:** $O(n)$
  - the flat depth array
