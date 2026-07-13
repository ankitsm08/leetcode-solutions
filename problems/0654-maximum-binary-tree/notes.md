## Monotonic Stack (Cartesian Tree)

### Intuition

The naive recursive approach scans for the max each time, costing $O(n^2)$. But notice the structure is a Cartesian tree, every node is the maximum between its left and right subtrees. A monotonic decreasing stack can use this property and build the tree in a single pass.

### Approach

Iterate left to right, maintain the right spine of the tree on a stack, and when a larger value appears, pop the spine to reassign it as the new node's left subtree.

#### Prep

- stack stores the rightmost path of the partially-built tree (nodes whose right child isnt yet finalised)
- sentinel with $+\infty$ keeps the stack non-empty, its `.right` will hold the final root

#### The Logic

- **Monotonic Decreasing Stack:**  
  Each new node pops every smaller element off the stack.  
  The last one popped becomes the new node's `left` child since it was the largest among the smaller elements, so it roots the left subtree of the new maximum
- **Right-Spine Linking:**  
  After popping, the new top sets the new node as its `right` child. This keeps the right spine invariant, since every un-popped element is larger than the new node

#### Getting the result

- `sentinel.right` points to the root of the complete tree (the global maximum)

---

### Complexity

- **Time Complexity:** $O(n)$
  - each node is pushed and popped at most once
- **Space Complexity:** $O(n)$
  - the stack can hold up to $n$ nodes in the worst case (strictly decreasing input)
