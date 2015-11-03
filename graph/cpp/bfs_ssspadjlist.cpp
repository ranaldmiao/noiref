vector<int> adjList[N];
int dist[N];
queue<int> q;

memset(dist, -1, sizeof(dist));
dist[S] = 0;
q.push(S);
while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        if (dist[*it] != -1) continue;
        dist[*it] = dist[x] + 1; //Assumes edge weight to be 1
        q.push(*it);
    }
}
