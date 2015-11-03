int fw[H][W]; //x for H, y for W
void update(int x, int y, int v) {
    for (int tx=x; tx<H; tx+=tx&(-tx))
        for(int ty=y; ty<W; ty+=ty&(-ty)) 
            fw[tx][ty] += v;
}
int sum(int x, int y) {
    int res = 0;
    for (int tx=x; tx; tx-=tx&(-tx))
        for(int ty=y; ty; ty-=ty&(-ty)) 
            res += fw[tx][ty];
    return res;
}
int rangesum(int x1, int y1, int x2, int y2) {  //Inclusive of (x1, y1) and (x2, y2)
    return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}