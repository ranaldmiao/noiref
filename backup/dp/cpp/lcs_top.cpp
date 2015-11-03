char a[MAXLEN+3], b[MAXLEN+3]; //Extra for the \n, \r, \0 just in case
int dp[MAXLEN+1][MAXLEN+1]; //dp[lena+1][lenb+1]

int lcs (int la, int lb) {
    if (la == 0 || lb == 0) return 0;
    if (dp[la][lb] != -1) return dp[la][lb];
    dp[la][lb] = max(lcs(la-1, lb), lcs(la, lb-1));
    if (a[la-1] == b[lb-1]) dp[la][lb] = max(dp[la][lb], dp[la-1][lb-1]+1);
    return dp[la][lb];
}

memset(dp, -1, sizeof(dp));
printf("%d\n", lcs(strlen(a), strlen(b)));