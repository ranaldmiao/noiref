struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum

/* UFDS */
int p[N];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]); }


sort(edgeList.begin(), edgeList.end(), cmp);
int ans = 0;
for (vector<edge>::iterator it = edgeList.begin(); it != edgeList.end(); ++it) {
    if (par(it->a) == par(it->b)) continue;
    p[par(it->a)] = par(it->b);
    ans += it->w;
}
