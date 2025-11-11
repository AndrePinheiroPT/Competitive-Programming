Important DP scenario, time complexity is usually $O(nW)$. 

We can implement 0/1 knapsack using 1D DP, like this

```c++
for(int i = 1; i <= n; i++)
    for (int j = W; j >= w[i]; j--)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
``` 

or using the 2D DP, like this

```c++
for (int i = 1; i <= n; i++)
    for (int j = 0; j <= W; j++)
        if (j-w[i]>=0) f[i][j] = max(f[i-1][j-w[i]] + v[i], f[i-1][j])
        else f[i][j] = f[i-1][j]
```

**In this version, its important to fill the gaps caused by ``j-w[i]>=0``!**

Similary, complete knapsack can be done like this

```c++
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= W; j++)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
```