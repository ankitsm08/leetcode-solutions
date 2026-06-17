Only x coordinates matter and goal is to find maximum gap between adjacent values.  
Used buckets to avoid sorting, max gap is between buckets not inside them.

`min(max(gap))` is the bucket width, the answer must be `>=` of that  
`gap = current.min - previous.max`  
skipping empty buckets, take max gap

- method is known as "bucket method"
- specifically maximum gap (pegionhole) technique

---

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(n)$
