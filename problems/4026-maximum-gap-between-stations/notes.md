## Greedy Bounds per Consecutive Pair

### Intuition

For the gap between workers $k-1$ and $k$, the left worker wants to sit as early as possible and the right worker as late as possible. We can fix both extremes on our own: one greedy pass finds the earliest spot for each worker from the left, another finds the latest spot from the right. The two halves dont overlap, so we can just glue them together and hit every pair's best gap.

### Approach

Sweep right to remember the latest station for each worker, sweep left to find the earliest station of the previous worker, and take the max gap as we go.

#### Prep

- worker $i$ needs a station where `station[j] == skill[i]`
- assigned station indices must be strictly increasing
- `last[i]`: latest station worker $i$ can sit at, from the right greedy
- one `first` pointer tracks the earliest station of worker $i - 1$ during the scan

#### The Logic

- **Right Greedy:**  
  Start $l$ at $m - 1$ and walk left past stations that dont match until `station[l] == skill[i]`  
  save `last[i] = l`, then move $l$ one more step left so the next worker gets a smaller index
- **Inlined Left Greedy:**  
  While scanning for the answer, push `first` right until `station[first] == skill[i - 1]`  
  so we get the earliest spot for worker $i - 1$ without storing an array
- **Pair Tightness:**  
  In any valid assignment $j_{k-1} \ge$ `first` and $j_k \le$ `last[k]`  
  so the best gap for the pair is `last[k] - first`, and splicing the two greedy halves reaches it

#### Getting the result

- one worker means no gaps, so return `0`
- scan $i = 1 \cdots (n-1)$, pushing `first` to the previous workers earliest station
- keep track of $\max(\text{last}\texttt{[i]} - \text{first})$ as the answer

---

### Complexity

- **Time Complexity:** $O(n + m)$
  - each sweep moves its pointer forward across the station string once
- **Space Complexity:** $O(n)$
  - we store the last occurence index of each skill in stations in `last`
