## Moving Right and Shifting Cost

### Intuition

If we check every box by itself, we redo a lot of work. The trick is to notice that moving one box to the right changes the total cost in a simple way: balls behind us are now one step farther, balls ahead are now one step closer. So if we know the cost for box $i-1$, we can get the cost for box $i$ with just a little math.

### Approach

Figure out the cost for box $0$ first, then slide to the right and adjust.

#### Prep

- `answer[0]` adds up `position * (1 if ball there, 0 if not)` for the starting cost
- `ahead` counts balls at or to the right of where we are now
- `behind` counts balls to the left of where we are now

#### The Logic

- **Cost Sliding:**
  Going from box $i-1$ to box $i$, the new cost is `old cost + behind - ahead`  
  Balls behind us get one step farther (`+ behind`), balls ahead get one step closer (`- ahead`)

#### Getting the result

- `answer[0]` is ready after the first pass
- the second pass fills the rest using the slide formula

---

### Complexity

- **Time Complexity:** $O(n)$
  - one pass to set up, one pass to slide
- **Space Complexity:** $O(1)$
  - excluding answer array size
