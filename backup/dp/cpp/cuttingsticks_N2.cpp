int N, a[N+1], sv[N+1][N+1];
long long rsq[N+1], dp[N+1][N+1];
long long sum(int x, int y) {
	if (x == 0) return rsq[y];
	return rsq[y] - rsq[x-1];
}


memset(dp, 62, sizeof(dp));
rsq[0] = a[0];
for (int i = 1; i < N; ++i) rsq[i] = rsq[i-1]+a[i];
for (int i = 0; i < N; ++i) {
	dp[i][i] = 0;
	sv[i][i] = i;
}
for (int len = 1; len < N; ++len) {
	for (int x = 0; x+len < N; ++x) {
		int y = x+len;
		for (int k = sv[x][y-1]; k <= sv[x+1][y]; ++k) {
			if (dp[x][k]+dp[k+1][y] < dp[x][y]) {
				sv[x][y] = k;
				dp[x][y] = dp[x][k] + dp[k+1][y];
			}
		}
		dp[x][y] += sum(x, y);
	}
}
printf("%lld\n", dp[0][N-1]);