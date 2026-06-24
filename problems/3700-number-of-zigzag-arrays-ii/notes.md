## Matrix Exponentiation with Universe Flipping

### Intuition

With $n$ up to $10^9$, any linear $O(n)$ dynamic programming loop will instantly trigger a TLE error. However, because the state space $K \le 75$ is small and the DP transitions are linear additions of previous states, the entire transition logic can be modeled as a constant matrix. We can use binary matrix exponentiation to fast-forward through $10^9$ transitions in logarithmic time.

### Approach

Flatten the DP transitions into a small, fast-transition state matrix and uses binary exponentiation.

#### Prep

- Compress the range `[l, r]` down to $K = r - l + 1$ choices
- Build a $K \times K$ transition matrix describing valid moves
- Start with a state vector of size `K`, all initialized to `1`

#### Tricks (how calculations are skipped)

- **Universe Flip (8x speed increase):**  
  Normally, we would track both UP and DOWN states, which forces a bulky $2K \times 2K$ matrix.
  Instead, pretend every move is UP. After each step, "flip" the index (`u` = `K - 1 - u`) to simulate DOWN moves.
  Same transitions, half the states -> $8 \times$ less cubic work.
- **Stack-Allocated `array`:**  
  Using `vector` inside our multiplication loops forces asking for memory on the heap every single iteration.  
  Switching to `array` keeps the memory on the stack, making allocation virtually free.
- **Avoid Modulo Overuse:**  
  `% mod` is a expensive CPU operation.
  Use 128-bit integers (`__int128`) to accumulate the sum without overflow,  
  and do the modulo just once per row instead of every single iteration.
- **Cache-Friendly Loops (`i -> k -> j`):**  
  Swapping the inner loop variables makes sure we read memory in a straight, contiguous line instead of jumping around.  
  This means the CPU cache is always full of the data we need next.
- **Matrix-Vector Fast Path:**  
  Matrix-by-matrix math is $O(K^3)$, but vector-by-matrix is only $O(K^2)$.  
  Isolate the single state vector and multiply it directly,  
  skipping the expensive matrix squares whenever we can.

#### Getting the result

Raise transition matrix to the power of $n - 1$,  
and apply it by our initial state vector,  
sum all resulting states, and  
multiply by `2` (to account for the arrays starting by going DOWN)

---

### Complexity

- **Time Complexity:** $O(K^3 \log n)$
  - We do $O(K^3)$ matrix squaring exactly $\log_2(n)$ times
- **Space Complexity:** $O(K^2)$
  - For the static $K \times K$ array inside our Matrix struct
