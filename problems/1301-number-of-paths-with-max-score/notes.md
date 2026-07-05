## Space-Optimized Grid DP

### Intuition

We need to track both max sum and path counts from bottom-right to top-left. Since we only transition right, down, and diagonally, we can throw away most of the grid, just tracking the active row and the row below it to save space.

### Approach

Solve the board bottom-up using two row arrays to track maximum scores and path counts.

#### Prep

- set up two arrays representing the current row and the row below
- initialize the bottom right start cell with zero sum and one way
- create direction offsets to represent the right, down, and diagonal steps

#### Optimization

- **No-Modulo Addition:**  
  Avoiding the slow modulo division operator saves cpu cycles in hot loops.  
  Subtract the modulo value manually only if the sum exceeds the limit
- **Row Swap Optimization:**  
  Pointer swapping the two row arrays avoids copying entire vectors every iteration.  
  Clearing the swapped row at the end prepares it for the next run
- **Zero-Branch Corner Bootstrapping:**  
  Setting the bottom right cell before the loop naturally avoids corner branches.  
  Invalid out of bounds checks keep the start cell from overwriting itself

#### Getting the result

Just grab the final score and ways from the first element of our swapped row. If the path ways is zero, we return a fallback of zero.

---

### Complexity

- **Time Complexity:** $O(n^2)$
  - each board cell is visited exactly once
- **Space Complexity:** $O(n)$
  - only two rows of size n
