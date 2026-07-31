## Greedy with Partial Sort

### Intuition

With 8 keys available, the most frequent letters should be placed where they cost 1 press, the next 8 cost 2 presses, and so on. The mapping is free, so we just need to figure out the minimal pushes given letter frequencies.

### Approach

Sort frequencies descending, then the first 8 keys cost 1 each, next 8 cost 2 each, etc.

#### Prep

- count letter frequencies into an `array<int, 26>`
- there are 8 phone keys, so each press-depth level holds 8 letters

#### The Tricks

- **Partial sort with nth_element:**  
  Instead of a full $O(26 \log 26)$ sort, we run `nth_element` 3 times, each putting the next 8 largest values in their correct region. This is $O(3 \cdot 26)$ with no log factor.

- **Press-depth formula:**  
  After sorting, the i-th most frequent letter (0-indexed) needs `(i / 8 + 1)` presses because each level of 8 adds one more push.

#### Getting the result

- sum `(i / 8 + 1) * freq[i]` across all 26 letters after partial sort

---

### Complexity

- **Time Complexity:** $O(n + 3 \cdot 26) \approx O(n)$
  - counting is $O(n)$
  - three `nth_element` calls are $O(26)$ each
- **Space Complexity:** $O(26) = O(1)$
