## Constant Time Closed-form GCD Math Trick

### Intuition

We need $\gcd(\text{sum of first}\; n \;\text{odds}, \text{sum of first}\; n \;\text{evens})$.
Both sums have clean closed forms, so we can reduce the problem to pure number theory.

### Approach

Compute the two closed forms, factor out $n$, and use the fact that consecutive integers are coprime.

#### Prep

- first $n$ odd numbers: $1, 3, 5, \dots, (2n - 1)$
- first $n$ even numbers: $2, 4, 6, \dots, 2n$

#### The Tricks

- **Sum of first $n$ odds:**  
  The $k$-th odd is $2k - 1$, so $\displaystyle\sum_{k=1}^{n} (2k - 1) = 2 \cdot \frac{n(n+1)}{2} - n = n^2$

- **Sum of first $n$ evens:**  
  The $k$-th even is $2k$, so $\displaystyle\sum_{k=1}^{n} 2k = n(n+1)$

- **Coprime factor:**  
  $\gcd(n^2,\ n(n+1)) = n \cdot \gcd(n,\ n+1)$  
  Consecutive integers are always coprime:  
  Any $d$ dividing both $n$ and $n+1$ must divide their difference $(n+1) - n = 1$,  
  so $\gcd(n, n+1) = 1$

#### Getting the result

- $\gcd(n^2,\ n(n+1)) = n \cdot 1 = n$, return $n$

---

### Complexity

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(1)$
