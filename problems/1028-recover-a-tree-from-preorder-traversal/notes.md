## Stack-based Tree Reconstruction

### Intuition

The traversal encodes depth as dash count and emits nodes in preorder. This means each node's parent is the most recent node whose depth is exactly one less. A stack naturally captures this ancestry pattern because it mirrors the DFS call stack that produced the traversal.

### Approach

Parse depth from leading dashes, then repeatedly pop the stack until its size matches the node's depth, attach the new node to the parent at the stack top, then push the node.

#### Prep

- maintain a stack of `TreeNode`, representing the current path in the tree
- parse the string left to right, alternating between reading dashes and digits

#### The Logic

- **Stack Trimming by Depth:**  
  Before attaching a node, pop from the stack while `st.size() > depth`. After trimming, the stack top is the correct parent because the stack always holds nodes from root to current depth.

- **Left-First Attachment:**  
  If the parent's left child is null, attach there; otherwise attach to the right. This respects the preorder property and the constraint that a single child is always the left child.

#### Getting the result

- after processing all nodes, the stack bottom (first element) is the root; pop everything above it and return the root.

---

### Complexity

- **Time Complexity:** $O(n)$
  - each character from string is read once, and each node is pushed/popped once
- **Space Complexity:** $O(n)$
  - the stack holds up to the height of the tree in the worst case (skewed tree)
