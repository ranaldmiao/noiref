for (sum[0][0] = m[0][0], i = 1; i < r; i++) sum[i][0] = m[i][0] + sum[i - 1][0];
for (j = 1; j < c; j++) {
	sum[0][j] = m[0][j] + sum[0][j - 1];
	for (i = 1; i < r; i++) sum[i][j] = m[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
}
int mx = INT_MIN;
for (r1 = 0; r1 < r; r1++)
	for (c1 = 0; c1 < c; c1++)
		for (r2 = r1; r2 < r; r2++)
			for (c2 = c1; c2 < c; c2++) {
				dp[r1][c1][r2][c2] = sum[r2][c2]
								   - ((r1)?sum[r1 - 1][c2]:(0))
								   - ((c1)?sum[r2][c1 - 1]:(0))
								   + ((r1 && c1)?(sum[r1 - 1][c1 - 1]):(0));
				mx = max(mx, dp[r1][c1][r2][c2]);
			}