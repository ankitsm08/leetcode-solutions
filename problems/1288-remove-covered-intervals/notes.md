## Greedy Interval Elimination

### Intuition

We want to find intervals eaten up by larger ones. Checking every pair takes quadratic time, which sucks. Sorting by start times lets us scan linearly since a later interval can never cover an earlier one.

### Approach

Sort intervals by start times ascending and end times descending to resolve overlaps in a single linear pass.

#### Prep

- array `intervals` represents the input segments of `[start, end)`
- `right` tracks the maximum right boundary seen so far during our scan
- `result` counts the total number of unique non-covered intervals left

#### Logic and Tricks

- **Short-circuiting Lambda Sort:**  
  Sorting by start ascending and end descending ensures bigger intervals come first.
  If two intervals start at the same coordinate, the larger one covers the smaller one
- **Single-Variable Boundary Tracking:**  
  We skip checking the start coordinate during the loop because of our sort order.
  Any interval with `end <= right` is automatically covered by a previous interval

#### Getting the result

Each time we find an interval extending past `right`, we increment `result` and push our boundary forward.  
The loop filters out all covered segments, leaving the final count in `result`.

---

### Complexity

- **Time Complexity:** $O(n \log n)$
  - due to sorting, since the linear scan only takes $O(n)$
- **Space Complexity:** $O(\log n)$
  - auxillary space for sorting
