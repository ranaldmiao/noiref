typedef pair<int, int> pi;
vector<pi> adjList[N]; // pair.first is the node, pair.second is the edge weight
int dist[N];
bitset<N> inq;
queue<int> q;

memset(dist, -1, sizeof(dist));
inq.reset();
dist[S] = 0;
inq[S] = 1;
q.push(S);
while (!q.empty()) {
    int x = q.front();
    q.pop();
    inq[x] = 0;
    for (vector<pi>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        int nx = it->first, nd = dist[x]+it->second;
        if (dist[nx] != -1 && dist[nx] <= nd) continue;
        dist[nx] = nd;
        if (!inq[nx]) q.push(nx);
        inq[nx] = 1;
    }
}
