## Virtual 1D Array Reversal

### Intuition

Shifting a 2D grid $k$ times is identical to rotating a flat 1D array of size $m \times n$ to the right by $k$ positions. Instead of moving elements one by one or allocating a new grid, we can rotate the elements in place. Reversing blocks of the array naturally swaps their positions while preserving the relative internal order.

### Approach

We map 2D coordinates to virtual 1D indices and apply a three-step reversal technique to rotate the grid in-place.

#### Prep

- `m` and `n` represent the grid dimensions
- `total` represents the total number of elements in the grid
- we reduce $k$ modulo the total elements to handle wrap-around shifts

#### The Logic

- **Three Step Reversal:**  
  To rotate an array right by $k$ elements, we first reverse the entire array. This places the elements destined for the front at the front, but in reverse order. We then reverse the first $k$ elements, and finally reverse the remaining $total - k$ elements to restore their correct order.
- **Virtual 1D Coordinate Mapping:**  
  We map a virtual 1D index $idx$ to 2D coordinates using row $idx / n$ and column $idx \% n$. This allows us to perform swaps in-place without flattening the grid physically.

#### Getting the result

- the grid is modified in-place and returned directly

---

### Complexity

- **Time Complexity:** $O(m \times n)$
  - we swap each element at most twice during the three reversals
- **Space Complexity:** $O(1)$
  - the rotation is performed completely in-place using constant auxiliary memory
