int dp[V+1];
int r (int v) {
    if (v < 0) return -2;
    if (v == 0) return 0;
    if (dp[v] != -1) return dp[v];
    dp[v] = -2; //assume impossible
    for (int i = 0; i < C; ++i) {
        if (r(v-coin[i]) == -2) continue;
        if (dp[v] == -2) dp[v] = r(v-coin[i])+1;
        dp[v] = min(dp[v], r(v-coin[i])+1);
    }
    return dp[v];
}


memset(dp, -1, sizeof(dp)); //-1 represents not processed, -2 represents impossible
if (r(V) == -2) printf("No way\n");
else printf("%d\n", r(V));