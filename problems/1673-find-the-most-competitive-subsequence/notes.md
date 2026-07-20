## Monotonic Stack

### Intuition

Competitive obviously dictates that we prefer smaller numbers as early as possible in our output. If we encounter a smaller number, we want to discard our previously selected larger numbers.

However, we cant just discard everything because we must finish with exactly $k$ elements. We must track how many elements remain in the input array so we dont run out of numbers to complete the subsequence.

### Approach

We maintain a monotonic increasing stack of size up to $k$, popping larger elements only when the remaining input elements are sufficient to complete the subsequence.

#### Prep

- `subseq` represents the monotonic stack storing our chosen subsequence elements
- `n` stores the total size of the input array `nums`
- we reserve size $k$ for the stack vector to avoid reallocations

#### Logic and Optimizations

- **Safe Pop Condition:**  
  The formula $\text{size} + n - i > k$ checks if we have surplus elements.  
  The term $n - i$ represents the count of available elements left in `nums`.  
  Adding this to the current stack size gives the maximum possible size we can achieve.  
  If this sum is strictly greater than $k$, we can safely pop the top element without falling short of our target
- **Size Protection:**  
  We can only pop from the stack if the remaining elements in the input can still fill the subsequence.  
  This ensures we dont fall short of the required size $k$

#### Getting the result

- the stack `subseq` contains the optimal competitive subsequence

---

### Complexity

- **Time Complexity:** $O(n)$
  - each element is pushed and popped from the stack at most once
- **Space Complexity:** $O(k)$
  - auxiliary space is bounded by the stack which never exceeds size $k$
