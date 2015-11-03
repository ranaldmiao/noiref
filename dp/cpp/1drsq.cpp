int arr[N+1]; //Original Array
int sum[N+1]; //Array used by RSQ
int rsq(int x, int y) { return sum[y]-sum[x-1]; }

/* Pre-computation -> put in int main*/
memset(sum, 0, sizeof(sum)); //Not required if no multiple testcases
for (int i = 1; i <= N; ++i) sum[i] = sum[i-1] + arr[i];