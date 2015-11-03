int dp[M];

memset(dp, 0, sizeof(dp));
for (int i = 0; i < N; ++i) {
    for (int x = M; x >= s[i]; --x) {
        dp[x] = max(dp[x], dp[x-s[i]]+v[i]);
    }
}
int ans = 0;
for (int i = 0; i <= M; ++i) ans = max(ans, dp[i]);
