typedef pair<int, int> pi;
vector<pi> adjList[N]; // pair.first is the node, pair.second is the edge weight
int dist[N];

void dfs (int x) {
    for (vector<pi>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        if (dist[it->first] != -1) continue;
        dist[it->first] = dist[x] + it->second; 
    }
}

/* Usage */
memset(dist, -1, sizeof(dist));
dist[S] = 0;
dfs(S); //Dfs from source