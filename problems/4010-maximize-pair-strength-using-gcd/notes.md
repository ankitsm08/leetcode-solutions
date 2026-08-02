## Sorted Branch and Bound Pruning

### Intuition

Brute force evaluates all $O(n^2)$ pairs which leads to very high runtime complexity. Notice that `nums[i] * nums[j]` is the absolute upper bound for strength because `gcd(nums[i], nums[j])` $\ge 1$. If we sort the array descending, theoretical products decrease monotonically, allowing us to safely cut off search loops early when remaining theoretical products cant beat our current best strength.

### Approach

Sort the array descending and iterate pairs, pruning inner and outer loops whenever theoretical maximum products fall below current max strength.

#### Prep

- sort `nums` in descending order so largest products are evaluated first
- `maxStrength` tracks the highest pair strength found so far
- `n` stores array size

#### The Logic

- **Outer Loop Pruning:**  
  If the theoretical best pair `nums[i] * nums[i + 1]` is smaller than or equal to `maxStrength`, stop the entire search immediately because no remaining pair in the array can beat the current best
- **Inner Loop Pruning:**  
  If `nums[i] * nums[j]` falls below or equals `maxStrength`, break the inner loop early since further `j` indices with the same `i` will only yield even smaller products

#### Getting the result

- return `maxStrength` after all loops finish or break early

---

### Complexity

- **Time Complexity:** $O(n \log n)$ average
  - sorting takes $O(n \log n)$
  - pruning drops the worst-case $O(n^2)$ loop iterations to a tiny fraction of operations
- **Space Complexity:** $O(1)$
