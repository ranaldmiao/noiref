#include <cstdio>
#include <cstring>
using namespace std;
char grid[505][505];
bool visited[505][505];
int h, w;
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
bool inBox (int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (x >= h || y >= w) return 0;
	return 1;
}
void dfs(int x, int y) {
	if (visited[x][y]) return;
	visited[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dirx[k], ny = y + diry[k];
		if (!inBox(nx, ny)) continue;
		if (grid[nx][ny] != 'H') continue;
		dfs(nx, ny);
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
			dfs(i, j);
		}
	}
	printf("Oh, bother. There are %d pools of hunny.", hunny);
}

