For given `j`, triplet if fully defined by `nums[j]`

So we only need to check if,  
`nums[i] - diff` and `nums[k] + diff` exist

Check for those numbers by looking up a hash table,  
of all the numbers in the array.
