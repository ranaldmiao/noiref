int dp[M+1][N], ans = 0;
int r (int x, int i) {
    if (i < 0) return 0;
    if (dp[x][i] != -1) return dp[x][i];
    dp[x][i] = r(x, i-1);
    if (s[i] <= x) dp[x][i] = max(dp[x][i], r(x-s[i], i-1)+v[i]);
    return dp[x][i];
}


memset(dp, -1, sizeof(dp)); //-1 means not processed
int ans = r(M, N-1);