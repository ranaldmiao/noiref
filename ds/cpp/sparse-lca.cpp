/* Pre-computation using DFS */
const int MAXN = 100050;
const int LOGN = 17;
int p[LOGN+1][MAXN], h[MAXN];   //h: number of edges from root
long long d[MAXN];     //dist: sum of edge weight from root
vector<pair<int, int> > adjList[MAXN];   //node, weight
bitset<MAXN> visited;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x] == -1) break;
        p[k+1][x] = p[k][p[k][x]];
    }
    for (auto it:adjList[x]) {
        if (visited[it.first]) continue;
        p[0][it.first] = x;
        d[it.first] = d[x] + it.second;
        h[it.first] = h[x] + 1;
        dfs(it.first);
    }
}

/* Query */
int lca(int a, int b) { //h[a] < h[b]
    if (h[a] > h[b]) swap(a, b);
    /* advance b by h[b] - h[a] parents */
    for (int k = 0, d = h[b] - h[a]; k < LOGN; ++k) {
        if (d & (1<<k))  b = p[k][b];
    }
    if (a == b) return a;
    assert(h[a] == h[b]); //same height
    /* to be continued */
    for (int k = LOGN-1; k >= 0; --k) {
        if (p[k][a] != p[k][b]) 
            a = p[k][a], b = p[k][b];
    }
    assert(p[0][a] == p[0][b]);		//same immediate parent
    return p[0][a];
}
