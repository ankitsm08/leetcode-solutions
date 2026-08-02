## Parity Win Guarantee Constant Time

### Intuition

With `n` even, the whole game collapses into a parity argument: the piles can be split into even-indexed positions and odd-indexed positions, two equal-size classes. Alice, going first, can pre-commit to capturing every pile in one parity class - whichever end she takes, it carries a fixed parity, and Bob, forced to respond, keeps handing her one of her own class. Since the classes have equal size, she can always grab the last pile of her class too, out-lasting Bob. Because the total pile sum is odd, the two classes cannot tie, so Alice can pick the heavier class and win outright.

The answer is unconditionally true, so no DP or game simulation is needed.

### Approach

Alice locks into one parity class at the start, conceding the other to Bob, and out-accumulates him by following her class to the end.

#### Prep

- `n` even and total odd, guaranteed by constraints
- split indices conceptually into even and odd classes
- Alice knows both class sums before moving

#### Logic

- **Ends Opposite Parity:**
  The two ends of the current row always sit in opposite classes, so Alice is guaranteed one pick of her class at every turn.

- **Equal Class Sizes:**
  Even `n` splits the piles evenly, so Bob's moves are confined to the other class and Alice drains hers fully.

- **Odd Total Decides Winner:**
  With an odd sum, the two class totals differ, so the class Alice chose can be the strictly larger one.

#### Getting the result

- Alice picks the larger class's parity, picks them turn by turn, and wins. Just `return true`

---

### Complexity

- **Time Complexity:** $O(1)$
  - constant work, the parity argument needs no iteration
- **Space Complexity:** $O(1)$
