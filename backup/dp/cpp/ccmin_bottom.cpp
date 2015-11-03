int dp[V+1];

memset(dp, -1, sizeof(dp)); //-1 represents no way here
dp[0] = 0;
for (int i = 0; i < C; ++i) {
    for (int x = coin[i]; x <= V; ++x) {
        if (dp[x-coin[i]] == -1) continue;
        if (dp[x] == -1) dp[x] = dp[x-coin[i]]+1;
        dp[x] = min(dp[x], dp[x-coin[i]]+1);
    }
}

if (dp[V] == -1) printf("No way\n");
else printf("%d\n", dp[V]);