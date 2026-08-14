## Segment Tree with Monoid Merge

### Intuition

After every point update we need the global longest run of identical characters. Recomputing by scanning the whole string per query is $O(k \cdot n)$, way too slow for $n, k \le 10^5$. The trick is that a run length across a boundary is fully determined by the left segment's suffix run, the right segment's prefix run, and whether the boundary characters match. That property is local, so it composes, which means we can fold it into a segment tree and combine answers in $O(1)$ per node.

### Approach

Build a segment tree where each node caches the prefix run, suffix run, and best run of its interval, then fold the cache up through merges so the root always holds the global answer.

#### Prep

- each node stores `left`, `right`, `pref`, `suff`, `max_len`, `len`
- `pref` is the longest run starting at the left edge of the interval
- `suff` is the longest run ending at the right edge of the interval
- `max_len` is the longest run anywhere in the interval
- leaves are built as `Node(s[i], 1)`, all runs of length $1$

#### The Logic

- **Boundary Crossing:**  
  New candidates only appear at the seam between two children.  
  If `L.right == R.left`, the two runs can join into `L.suff + R.pref`
- **Prefix/Suffix Extension:**  
  `pref` can only grow past the seam if the whole left child is one run (`L.pref == L.len`), because any internal boundary would break the prefix.  
  Symmetrically, `suff` extends into the left child only when `R.suff == R.len`
- **Correctness by Monoid:**  
  Every node's `max_len = max(L.max_len, R.max_len, joined seam)`  
  Since the seam candidate covers exactly the runs that span both children, no answer is missed

#### Getting the result

- point update touches one path to a leaf and re-merges up through its ancestors
- the root node's `max_len` is the answer after each of the $k$ queries

---

### Complexity

- **Time Complexity:** $O(n + k \log n)$
  - build is $O(n)$, each point update walks one root-to-leaf path
- **Space Complexity:** $O(n)$
  - the tree is stored in a flat array of size $4n$
