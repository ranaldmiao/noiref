vector<int> adjList[N];
bool visited[N];

void dfs (int x) {
    if (visited[x]) continue;
    visited[x] = 1;
    for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        if (visited[*it]) continue; //add additional checks here
        dfs(*it);
    }
}

/* Usage */
int num_pools = 0;
memset(visited, 0, sizeof(visited)); //set all to be unvisited
for (int i = 0; i < N; ++i) {
    if (visited[i]) continue;
    ++num_pools;
    dfs(i);
}