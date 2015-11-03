char a[MAXLEN+3], b[MAXLEN+3]; //Extra for the \n, \r, \0 just in case
int dp[MAXLEN+1][MAXLEN+1]; //dp[lena+1][lenb+1]

int lena = strlen(a), lenb = strlen(b);
memset(dp, 0, sizeof(0));
for (int i = 1; i <= lena; ++i) {
    for (int j = 1; j <= lenb; ++j) {
        if (a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
}
printf("%d\n", dp[lena][lenb]);