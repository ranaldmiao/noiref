int dp[V+1];

memset(dp, 0, sizeof(dp));
dp[0] = 1;
for (int i = 0; i < C; ++i) {
    for (int x = C[i]; x <= V; ++x) {
        dp[x] += dp[coin[i]];
    }
}
printf("%d\n", dp[V]);