## Two-Pointer Stable Partition

### Intuition

We need to rearrange elements while keeping relative order of `< pivot` and `> pivot` groups intact. We can do it in one pass by placing elements from both ends simultaneously. Pre-filling the result with `pivot` means we only need to place the non-pivot elements.

### Approach

Use two pointers moving inward from both ends.  
One fills `< pivot` from the left and the other fills `> pivot` from the right.

#### Prep

- `ans` is initialized with size `n`, default-filled with `pivot`
- `front` starts at `0`, `back` starts at `n - 1`
- `i` walks forward, `j` walks backward

#### The Logic

- **LIFO order preservation:**  
  The backward pointer encounters `> pivot` elements from right to left and places them at `ans[back]`.  
  Rightmost elements land at the far end, subsequent ones settle just before them, so left-to-right reading preserves original relative order
- **Default pivot fill:**  
  Elements equal to `pivot` are never explicitly placed, they already occupy the middle gap via the initial `ans` fill

#### Getting the result

- return `ans` directly after the loop, since every `<` and `>` element is placed by one of the two pointers and the remaining slots hold `pivot`

---

### Complexity

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(n)$
