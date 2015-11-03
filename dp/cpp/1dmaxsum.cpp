int arr[N];
int cursum = arr[0], ans = arr[0];
for (int i = 1; i < N; ++i) {
    if (cursum < 0) cursum d= 0;
    cursum += arr[i];
    ans = max(ans, cursum);
}