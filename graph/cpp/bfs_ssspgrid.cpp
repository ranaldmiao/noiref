typedef pair<int, int> pi;
char grid[H+1][W+1];

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dist[H+1][W+1];
queue<pi> q;

memset(dist, -1, sizeof(dist));
dist[sx][sy] = 0;
q.push(make_pair(sx, sy));
while (!q.empty()) {
    pi cur = q.front();
    q.pop();
    int x = cur.first, y = cur.second;
    for (int i = 0; i < 4; ++i) { //Change '4' to 8 for 8 directions
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;
        if (nx >= H || ny >= W) continue;
        if (dist[nx][ny] != -1) continue;
        if (grid[nx][ny] == 'X') continue; //Check other conditions here
        dist[nx][ny] = dist[x][y]+1; //Assumes edge weight to be 1
        q.push(make_pair(nx, ny));
    }
}