int fw[N]; //initialize everything to 0
void update(int x, int v) {
    for (; x<N; x+=x&(-x)) fw[x] = max(fw[x], v); 
}
int sum(int x) {
    int res = 0;
    for(; x; x-=x&(-x)) res = max(res, fw[x]);
    return res;
}