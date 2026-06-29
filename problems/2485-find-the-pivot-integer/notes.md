### Intuition

This looks like a very simple Math problem of Arithmetic Progression.

### Approach

The core math of the problem is,

$\text{sum}(1\ldots x) = \text{sum}(x \ldots n)$

Using arithmetic series formulas,

$\dfrac{x(x+1)}{2} = \dfrac{n(n+1)}{2} - \dfrac{(x-1)x}{2}$

Simplify that and we get:

$x = \sqrt{\dfrac{n(n+1)}{2}}$

Check whether $\dfrac{n(n+1)}{2}$ is a perfect square and returning that square root if it is, or `-1` otherwise.

### Complexity

- **Time:** $O(1)$
- **Space:** $O(1)$
