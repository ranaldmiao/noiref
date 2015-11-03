int arr[H+1][W+1][D+1]; //Original Array
int sum[H+1][W+1][D+1]; //Array used by RSQ
int rsq(int x1, int y1, int z1, int x2, int y2, int z2) { 
    return sum[x2][y2][z2] 
    - sum[x2][y2][z1-1] - sum[x2][y1-1][z2] - sum[x1-1][y2][z2] 
    + sum[x2][y1-1][z1-1] + sum[x1-1][y2][z1-1] + sum[x1-1][y1-1][z2] 
    - sum[x1-1][y1-1][z1-1];
}

/* Pre-computation -> put in int main*/
memset(sum, 0, sizeof(sum)); //Not required if no multiple testcases
for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
        for (int k = 1; k <= D; ++k) {
            sum[i][j][k] = sum[i][j][k-1] + sum[i][j-1][k] + sum[i-1][j][k] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1] + sum[i-1][j-1][k-1] + arr[i][j][k];
        }
    }
}