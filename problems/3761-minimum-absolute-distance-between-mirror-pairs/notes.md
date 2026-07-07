## One-Pass Hash Map + Reverse Lookup

### Intuition

We just need to track the latest encountered index of the reverse of current number. This can be simply done using an unordered hashmap.

### Approach

One left-to-right pass using a hash map to link each number's reverse to its index.

#### Prep

- hashmap key is the reversed number, value is the latest index where that number appeared
- minimum distance starts at infinity and shrinks as matching pairs are found

#### Tricks

- **Return at 1:**  
  Distance can't go below 1, early return the moment you spot an adjacent pair

- **`pmr::unsynchronized_pool_resource` instead of Default Allocator:**  
  Default allocator calls `malloc` per node which is many tiny heap requests, scattered memory, cache-horrible.  
  `pmr` grabs one big block and sub-allocates nodes contiguously from it.

  It's required to include this header to use `pmr`:

  ```cpp
  #include <memory_resource>
  ```

#### Getting the result

Return minimum distance if any pair was found, otherwise `-1`.

---

### Complexity

- **Time Complexity:** $O(n)$
  - each reversal iterates at most 10 digits, effectively constant
- **Space Complexity:** $O(n)$
  - for the hash map, worst case every number is unique
