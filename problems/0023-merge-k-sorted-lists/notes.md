Use **priority queue** (min heap) to store the `k` nodes with minimum values.

Pop one out, link it to `curr`, and push its next node into the heap, if it exists. We are done when the queue is empty.

---

- **Time Complexity:** $O(n \log k)$
  - total `2n` operations done on min heap with `k` elements at most at a time
- **Space Complexity:** $O(k)$
  - size of the min heap to store the node references
