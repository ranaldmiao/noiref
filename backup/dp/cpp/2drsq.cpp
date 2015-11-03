int arr[H+1][W+1]; //Original Array
int sum[H+1][W+1]; //Array used by RSQ
int rsq(int x1, int y1, int x2, int y2) { return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]; }

/* Pre-computation -> put in int main*/
memset(sum, 0, sizeof(sum)); //Not required if no multiple testcases
for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
        sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
    }
}