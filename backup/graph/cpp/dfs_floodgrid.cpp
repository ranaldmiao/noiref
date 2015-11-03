char grid[H+1][W+1];

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1,  0, 0, 1, -1, 1, -1};
bool visited[H+1][W+1];

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; ++i) { //Change  '4' to '8' for 8 directions
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;
        if (nx >= H || ny >= W) continue; //Edit if 1 index-ed
        if (visited[nx][ny]) continue; 
        if (grid[nx][ny] == 'X') continue; //Check other conditions here
        dfs(nx, ny);
    }
}

/* Usage */
int num_pools = 0;
memset(visited, 0, sizeof(visited)); //set all to be unvisited
for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
        if (grid[i][j] == 'X') continue;
        if (visited[i][j]) continue;
        ++num_pools;
        dfs(i, j);
    }
}