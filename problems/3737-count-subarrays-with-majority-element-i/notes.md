## Balance Prefix and Frequency Sweep

### Intuition

Majority just means `target` beats everything else combined. So instead of thinking in counts and halves, flip it into a balance problem: `+1` for `target`, `-1` for everything else. Any subarray where this balance is positive is valid.

### Approach

Track prefix balance while sweeping once, and keep a running count of how many earlier balances are smaller than the current one.  
a.k.a. Prefix over Prefix Sum

#### Prep

- Treat `target` as `+1`, non-target as `-1`
- Maintain a running **balance**, `prefix[]` where `prefix[b]` = how many times balance `b` has appeared
- Offset balance by `n` so indices stay non-negative, `prefix[n] = 1` since at start balance is `0`
- `query` = number of previous prefixes strictly smaller than current balance

#### Tricks Used

- **$\pm 1$ Balance Trick:**  
  Each step only shifts balance by `+1` or `-1`, so the set of "smaller balances" changes locally.

  For current balance `b`:
  - Move to `b + 1`: all old `b` become valid => `query += prefix[b]`
  - Move to `b - 1`: old `b - 1` no longer valid => `query -= prefix[b - 1]`

- **Prefix-over-Prefix Counting:**  
  Since each element changes balance by only `+1` or `-1`, the number of valid earlier prefixes can be updated directly:
  - if current value is `target`, the balance goes up, so more earlier balances become smaller
  - otherwise the balance goes down, so some earlier balances stop being smaller

  Here, `query` = count( { `i < r` | `pref[i]` < `pref[r]` } )  
  That is why `query` can be maintained in $O(1)$ instead of doing a separate search or tree query.

#### Getting the result

At each index, `query` directly equals the number of majority-valid subarrays ending there. Accumulate it into `total` and that's the answer.

---

### Complexity

- **Time Complexity:** $O(n)$
  - single pass, constant work per element
- **Space Complexity:** $O(n)$
  - for the frequency array over possible balances
