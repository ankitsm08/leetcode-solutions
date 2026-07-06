## Constant Time Math Trick

### Intuition

Honestly just realized any number in base $n - 2$ evaluates to $12$. Also even numbers fail the binary base immediately since they end with zero.

### Approach

Skip the simulation entirely and just return false since nothing can pass (for $n \ge 4$).

#### Prep

No prep required.

#### The Logic

- **Math Trick:**  
  Base $n - 2$ always evaluates to $12$ saving us from doing loop checks
- **Binary Trap:**  
  Even numbers end in zero for base 2 preventing any valid palindrome.  
  This covers our $n = 4$ base condition

#### Getting the result

Hardcode false as the return value to beat the problem with zero overhead.

---

### Complexity

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(1)$
