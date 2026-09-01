## In-place Preorder Flatten (Predecessor Splicing)

### Intuition

Preorder visits `root` then `left` then `right`, and the flattened list must follow that same order with `left` always `nullptr`. When `root->left` is empty we are already in order and just advance, otherwise the left subtree belongs right after `root`.

Tiny example `1(2(3,4),5(,6))` -> preorder is `1,2,3,4,5,6` so we must insert `2,3,4` between `1` and `5` and link `4->right` to `5`.

### Approach

Splice the left subtree between current node and its old right by wiring the rightmost node of left to the old right, then walk right.

#### Prep

- `root` cursor starts at original root and follows the growing right spine
- `end` predecessor starts at `root->left` and walks only `right` to reach rightmost node
- no stack or recursion needed, we reuse existing tree pointers only

#### The Logic

- **Preorder Splicing:**  
  When `root->left` exists we cut it out and insert it immediately after `root`.  
  This preserves preorder because everything from left must come before old `right` and no copy is needed.

- **Rightmost Predecessor Wiring:**  
  The rightmost node of `left` is the last node of its preorder, so its `right` must point to saved `oldRight`.  
  Finding it costs the length of that right spine and each edge is moved to the spine at most once.

  Each node joins the spine once, so total work is linear:

  $$T(n) = O(n)_{\text{outer}} + O(n)_{\text{pred}} = O(n)$$

#### Getting the result

- outer loop advances `root = root->right` until `nullptr`
- when loop exhausts, `left` is `nullptr` everywhere and `right` holds preorder sequence

---

### Complexity

- **Time Complexity:** $O(n)$
  - each node becomes part of right spine once, total predecessor walks are $O(n)$
- **Space Complexity:** $O(1)$
  - only two pointers `root` and `end`, no stack or allocation
