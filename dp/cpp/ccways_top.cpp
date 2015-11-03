int dp[V+1][C];
int r (int v, int c) {
    if (v < 0) return 0;
    if (v == 0) return 1;
    if (c < 0) return 0;
    if (dp[v][c] != -1) return dp[v][c];
    dp[v][c] = r(v, c-1);  //Dont take current coin
    dp[v][c] += r(v-coin[c], c); //Take one instance of current coin
    return dp[v][c];
}

memset(dp, -1, sizeof(dp));
int ans = r(V, C-1);