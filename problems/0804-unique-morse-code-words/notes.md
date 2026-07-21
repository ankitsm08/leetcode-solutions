## Hash Set (easier)

### Intuition

We can build the full Morse string per word, dump it into a set, and read the set size. The input constraints ($N \le 100$, $L \le 12$) make this perfectly fine.

### Approach

Concatenate Morse codes for each word and insert into a hash set.

#### Prep

- static morse table
- `unordered_set<string>` to store seen transformations
- a static `string` buffer reused across words to avoid allocations

#### Trick

- **Reusable Buffer:**
  Clear the buffer each word, then `append` each letter's Morse code. Insert the buffer into the set.

#### Getting the result

- return `set.size()`

---

### Complexity

- **Time Complexity:** $O(N \cdot L)$
  - building each string and hashing it is linear in total Morse symbols
- **Space Complexity:** $O(N \cdot L)$
  - stores one string per unique transformation

---

## Trie Counting (complex)

### Intuition

We can encode each word's Morse code directly into a trie without ever building the full string. Each node branches on `.` (dot) or `-` (dash). By counting how many words terminate at a _new_ leaf, we tally unique transformations in one pass.

### Approach

Insert each word's Morse symbols into a trie; each freshly terminated leaf increments a unique counter.

#### Prep

- static morse table `a-z` -> `.-` strings, each 1-4 symbols long
- static `vector<TrieNode>` with `children[2]` (index 0 for `.`, index 1 for `-`), and `is_end` flag
- `unique_count` int to track newly terminated words

#### Logic

- **Bit-Indexed Children:**
  Map `.` to `0` and `-` to `1` with `(m == '-')`. This gives us `children[bit]` as the next node index.
- **Lazy Node Allocation:**
  If `children[bit]` is 0, push a new node and assign its index. This avoids pre-allocating a fixed-size grid.

#### Getting the result

- after fully inserting a word, check if the leaf's `is_end` is already set
- if not, set it and bump `unique_count`
- return `unique_count`

---

### Complexity

This solution is slightly overkill for the given constraints ($N \le 100$, $L \le 12$).

- **Time Complexity:** $O(N \cdot L)$
  - each letter expands to 1-4 Morse symbols; each symbol is one node traversal or creation
- **Space Complexity:** $O(N \cdot L)$
  - each unique Morse path materializes nodes; worst case is every word being unique
