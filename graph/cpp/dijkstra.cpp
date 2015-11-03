typedef pair<int, int> pi;
vector<pi> adjList[N]; // pair.first is the node, pair.second is the edge weight
int dist[N];
priority_queue<pi, vector<pi>, greater<pi> > pq;

memset(dist, -1, sizeof(dist));
dist[S] = 0;
pq.push(make_pair(0, S));
while (!q.empty()) {
    pi cur = q.top();
    q.pop();
    int x = cur.second, d = cur.first;
    if (d > dist[x]) continue;
    for (vector<pi>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        int nx = it->first, nd = d+it->second;
        if (dist[nx] != -1 && dist[nx] <= nd) continue;
        dist[nx] = nd;
        pq.push(make_pair(nd, nx));
    }
}
