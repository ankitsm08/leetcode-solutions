First, we dont need to look at all the elements  
to know what the median is.

The median is the number for which:

- all numbers on the left < median
- median < all numbers on the right

The problem being, the array is split in two.  
But since they are sorted:

For a given `i`, where it denotes the number of elements taken from first array,  
we know the number of elements to be taken (`j`) from the second array.

`j` = `(m + n + 1) / 2 - i`

The split of numbers is correct if:

- `arr1[i - 1]` <= `arr[j]`
- `arr2[j - 1]` <= `arr[i]`

thus we found our solution.

If not, then we adjust our `low` and `high` values and recalculate,

`i` = `(low + high) / 2` and `j`

until we find the solution or `low` > `high` (unreachable)

Edge Cases:

if `i or j == 0`, treat array values like `-inf`  
if `i == m or j == n`, treat array values like `inf`

and to avoid `j < 0`, `m <= n` must hold true

---

- **Time Complexity:** $O(\log m)$
  - if `m < n`, else $O(\log n)$
- **Space Complexity:** $O(1)$
