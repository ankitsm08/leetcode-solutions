## Compile-Time Generation and Binary Search

### Intuition

Instead of running DFS or BFS at runtime to generate combinations, we look at the mathematical constraints. There are only 36 possible numbers with sequential digits between lengths 2 and 9. We dont want to hardcode a magic array, so we make the compiler compute it.

Generating them ordered by length then starting digit naturally yields a strictly sorted sequence. Since the array is sorted and baked into the binary, we just do a quick binary search at runtime to pull the range we need.

### Approach

We generate all possible sequential numbers at compile time and use binary search to slice out the valid bounds.

#### Prep

- define constants for max digit value, min length, and max length
- calculate the total possible answers algebraically to set the array size
- use an immediately invoked lambda (IIFE) to populate the `constexpr std::array`

#### The Tricks

- **Zero-Cost Abstraction**:  
  We use `constexpr` on the array and its generator lambda (IIFE).  
  The compiler evaluates all loops and math during compilation, so the array is embedded in read-only memory and runtime generation costs exactly $O(1)$
- **Natural sorting**:  
  By iterating length first, then starting digit, the generated values are strictly ascending.  
  This allows us to use standard binary search algorithms without a separate sorting step
- **Shrinking the search space**:  
  When finding the upper bound for `high`, we pass `begin` instead of `possible.begin()`  
  Since `high >= low`, this reuses the result of our first search and narrows the space for the second

#### Getting the result

- return a vector constructed directly from the start and end iterators
- avoids manual loops and push operations entirely

---

### Complexity

- **Time Complexity:** $O(\log K) \approx O(1)$
  - where $K = 36$ is the total number of possible sequential digits
  - finding the range takes $O(\log K)$, where maximum value of $\log K$ is $6$
- **Space Complexity:** $O(1)$
  - the computed array is in the executable memory, so we only use constant extra stack space
