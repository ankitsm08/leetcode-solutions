## Backtracking with Fibonacci Pre-allocation

### Intuition

The obvious approach is generating all $2^n$ binary strings and filtering out ones with adjacent zeros. But we can prune during construction, and more importantly we know exactly how many valid strings there are before we start.  
That count follows a Fibonacci recurrence: a length-$n$ valid string either starts with `1` (rest is any valid $n-1$ string) or `0` followed by `1` (rest is any valid $n-2$ string).  
So $S(n) = S(n-1) + S(n-2)$, same recurrence as Fibonacci, with $S(1) = 2$ and $S(2) = 3$.

### Approach

Backtrack with in-place string mutation, and pre-reserve the exact output capacity from the Fibonacci table to eliminate reallocation overhead.

#### Prep

- precompute `FIB[1..20]` at static init time via an IIFE so `answer.reserve(FIB[n + 2])` allocates exactly once
- `current` is a single string passed by reference, mutated with `push_back`/`pop_back`
- `solve(idx, current, answer, n)` where `idx` is the position being filled

#### The Tricks

- **In-place mutation:**
  Instead of building new strings at each call, we push and pop on one string object, avoiding $O(n)$ copy per recursive step
- **Fibonacci pre-allocation:**
  `FIB[n + 2]` gives the exact number of valid strings, reserving the size removes dynamic allocation overhead
- **Pruning the `0` branch:**
  We only place `0` when `current` is empty or the last char isnt `0`, so we never explore dead paths that would have adjacent zeros

#### Getting the result

- at `idx == n`, push a copy of `current` into the pre-allocated `answer` (this is the only string copy per result)
- recursion unrolls and the filled vector returns

---

### Complexity

- **Time Complexity:** $O(n \cdot F_{n+2})$
  - we visit exactly $F_{n+2}$ base cases, each copying a length-$n$ string
  - internal nodes are also $O(F_{n+2})$ total

- **Space Complexity:** $O(n \cdot F_{n+2})$
  - output holds $F_{n+2}$ strings of length $n$
  - recursion stack is $O(n)$
