## Backtracking with Early Termination (Bitwise OR Pruning)

### Intuition

Max OR is fixed as OR of all elements, so only counting matters.  
Brute force is fine since n is tiny, but prune aggressively.

### Approach

DFS all subsets but instantly count remaining choices once maxOR is reached.

#### Prep

- compute maxOR as OR of all elements upfront
- sort array descending to hit maxOR earlier in recursion
- dfs state is index and current OR value

#### Optimizations

- **OR Saturation Pruning:**  
  Once current OR equals maxOR, further picks cannot change it.  
  All remaining subsets are valid so count them in one shot.  
  Saves exploring $2^{(n - idx)}$ recursive calls

- **Ordering Heuristic:**  
  Sorting by descending values increases chance of early saturation.  
  Not required for correctness but improves average runtime

#### Getting the result

DFS directly returns the number of valid non-empty subsets.  
Empty subset never reaches maxOR so no post adjustment needed.

---

### Complexity

- **Time Complexity:** $O(2^n)$
  - worst case still exponential but heavily pruned in practice
- **Space Complexity:** $O(n)$
  - recursion depth only
