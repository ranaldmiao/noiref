int fw[N], fw2[N];
void update(int x, int y, int v) { //inclusive
    for (int tx=x; tx < N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty < N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
int sum (int x) {
    int res = 0;
    for (int tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
int range_sum(int x, int y) { //inclusive
    return sum(y)-sum(x-1);
}