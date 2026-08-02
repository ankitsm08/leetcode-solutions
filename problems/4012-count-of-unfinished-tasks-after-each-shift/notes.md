## Prefix Sum with Binary Search

### Intuition

Tasks are forced to run in order and progress carries across shifts, so total work done is a single scalar. The prefix sum tells us exactly when each task completes, turning "how many tasks finish with $t$ time" into one binary search.

### Approach

Prefix-sum the tasks, then for each shift binary search where the accumulated time lands.

#### Prep

- `prefix[i]` holds total time to finish tasks through index $i$
- `prev` tracks work time carried over since the last restart
- `prefix` resized to $n$, `ans` reserves $m$ slots
- use `long long` since cumulative times overflow `int`

#### The Logic

- **`upper_bound` Finishes Test:**  
  `upper_bound(prefix, prev + hours)` yields the first task whose completion time exceeds available time, so it and everything after is unfinished
- **Restart Resets `prev`:**  
  When `left == 0` all tasks finished, so `prev = 0` discards the unused shift time for free
- **`long long` Carry:**  
  `prev + hours` reaches $\approx 10^{14}$, way past `int` range

#### Getting the result

- `distance(it, prefix.end())` counts unfinished tasks directly
- push that count, then `prev` either accumulates `hours` or resets to $0$

---

### Complexity

- **Time Complexity:** $O(n + m \log n)$
  - prefix build costs $O(n)$, each shift runs one `upper_bound`
- **Space Complexity:** $O(n + m)$
  - `prefix` array of size $n$, `ans` of size $m$
