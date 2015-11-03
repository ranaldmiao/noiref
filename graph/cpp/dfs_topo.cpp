vector<int> adjList[N], topo;
bool visited[N];

void dfs (int x) {
    if (visited[x]) continue;
    visited[x] = 1;
    for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        if (visited[*it]) continue;
        dfs(*it);
    }
    topo.push_back(x);
}

/* Usage */
topo.clear();
memset(visited, 0, sizeof(visited)); 
for (int i = 0; i < N; ++i) {
    if (visited[i]) continue;
    dfs(i);
}
reverse(topo.begin(), topo.end()); //to get the correct topological order