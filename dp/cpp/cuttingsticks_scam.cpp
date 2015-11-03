#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc, N, a[2005];
ll rsq[2005], dp[2005][2005];
ll sum(int x, int y) {
	if (x == 0) return rsq[y];
	return rsq[y] - rsq[x-1];
}
int main () {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		memset(dp, 62, sizeof(dp));
		//printf("%lld\n", dp[0][0]);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
			dp[i][i] = 0;
		}
		rsq[0] = a[0];
		for (int i = 1; i < N; ++i) rsq[i] = rsq[i-1]+a[i];
		for (int len = 1; len < N; ++len) {
			int saveK = 0;
			for (int x = 0; x+len < N; ++x) {
				int y = x+len;
				int bestK = max(saveK, x);
				for (int k = bestK; k < y && k < bestK+10; ++k) {
					if (dp[x][k]+dp[k+1][y] < dp[x][y]) {
						bestK = k;
						dp[x][y] = dp[x][k] + dp[k+1][y];
					}
				}
				saveK = bestK;
				dp[x][y] += sum(x, y);
				//printf("%d %d: %lld\n", x, y, dp[x][y]);
			}
		}
		printf("%lld\n", dp[0][N-1]);
	}
}