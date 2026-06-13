[0, 1000] -> value range is tiny and fixed

Instead of checking every `i` for each `(j, k)`,  
count all valid `i` at once  
conditions are:

```
abs(arr[i] - arr[j]) <= a
abs(arr[i] - arr[k]) <= c
```

which become:

[arr[j]-a, arr[j]+a]
[arr[k]-c, arr[k]+c]

intersection:

[l, r] = [max(...), min(...)]

Any previous value in `[l, r]` is a valid `i`

Maintain, sum[x] = previous_values <= x  
then,  
count(values in [l, r]) = sum[r] - sum[l-1]  
so each `(j, k)` pair can count all valid `i` in O(1)

when value `v` is seen,
since `v <= x` for all those thresholds:

```
for x = v..1000:
  sum[x]++
```

---

say, `S` is size of value range

Time Complexity:  
Naive: O(n^3)  
Optimized: O(n² + n\*S)

Space Complexity:  
Naive: O(1)  
Optimized: O(S)
