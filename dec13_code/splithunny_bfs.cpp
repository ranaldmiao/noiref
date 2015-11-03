#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
#define mp make_pair
char grid[505][505];
bool visited[505][505];
int h, w, dist[505][505];
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
bool inBox (int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (x >= h || y >= w) return 0;
	return 1;
}
queue<pi> q;
void bfs (int x, int y) {
	q.push(mp(x, y));
	dist[x][y] = 0;
	visited[x][y] = 1;
	while (!q.empty()) {
		pi cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dirx[i], ny = cur.second + diry[i];
			if (!inBox(nx, ny)) continue;
			if (grid[nx][ny] != 'H') continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push(mp(nx, ny));
		}
	}
	
}
int main () {
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; ++i) {
		scanf("%s", grid[i]);
	}
	int hunny = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (visited[i][j]) continue;
			if (grid[i][j] != 'H') continue;
			++hunny;
			bfs(i, j);
		}
	}
	printf("Oh, bother. There are %d pools of hunny.", hunny);
}

