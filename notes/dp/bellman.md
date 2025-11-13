I call this the **DP-bellman** tecnique. Can be useful in problems with time complexity around $O(NM)$.

Basically, for any directed graph, we can apply the idea of Bellman-Forward algorithm to compute the DP transitions between nodes, where **the DP is not circular**. 

Here is the idea:

```c++
for(int i = 1; i<=M; i++)
    for(auto &[x,y]:edges)
        if(dp[x][i-1] != INF) 
            if(dp[x][i-1] + w[i] > dp[y][i])
                dp[y][i] = dp[x][i-1] + w[i]
```

Of course, if the graph is a DAG, topological sort is more applicable.

Exemple problems:

![Time is Mooney](../../USACO/Time%20is%20Mooney/time_is_mooney.cpp)

![A problem created by Caio (will ad later)](./bellman.md)
