/* Pre-computation using DFS */
const int MAXN = 100050;
const int LOGN = 17;
int p[LOGN+1][MAXN];
vector<int> adjList[MAXN];
bitset<MAXN> visited;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x] == -1) break;
        p[k+1][x] = p[k][p[k][x]];
    }
    for (auto it:adjList[x]) {
        if (visited[it]) continue;
        p[0][it] = x;
        dfs(it);
    }
}

/* Per query, d-th ancestor of x */
int ancestor(int x, int d) {
    for (int k = 0; k <= LOGN && x != -1; ++k) {
        if (d & (1<<k)) 
            x = p[k][x];
    }
    return x;
}