Each subset XOR is made by XOR-ing chosen elements.  
Instead of enumerating subsets, count bit contributions.

If a bit is set in any element, it appears in XOR results for half of all subsets.

For a given bit, choosing elements with that bit toggles it  
across all subsets, that bit is ON in exactly `2^(n-1)` subsets  
so,  
`or_all` tells which bits appear at least once,  
each such bit contributes `2^(n-1)` times

`subsetXORSum = (bitwise OR of all elements) * 2^(n-1)`

Time Complexity: O(n)
Space Complexity: O(1)
