int a[N]; //Original array
int dp[N], ans;


for (int i = ans = 0; i < N; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
        if (a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
    }
    ans = max(dp[i], ans);
}