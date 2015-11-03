#include <cstdio>
#include <vector>
using namespace std;
int n, q, num_child[100005], par[100005], seg[100005], segroot[100005], segdepth[100005], height[1000005], segcount;
vector<int> adjList[100005];
int count_child (int x, int p) {
	par[x] = p;
	num_child[x] = 1;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (*it == p) continue;
		num_child[x] += count_child(*it, x);
	}
	return num_child[x];
}
void decomp(int x, int s, int sd, int h) {
	seg[x] = s;
	height[x] = h;
	segdepth[x] = sd;
	int largest = -1;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (*it == par[x]) continue;
		if (largest == -1) largest = *it;
		if (num_child[largest] < num_child[*it]) largest = *it;
	}
	if (largest == -1) return;
	decomp(largest, s, sd, h+1);
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (*it == largest) continue;
		if (*it == par[x]) continue;
		segroot[++segcount] = x;
		decomp(*it, segcount, sd+1, h+1);
	}
}
int lca (int a, int b) {
	if (a == b) return a;
	if (seg[a] == seg[b]) {
		if (height[a] < height[b]) return a;
		else return b;
	}
	if (segdepth[a] > segdepth[b]) return lca(segroot[seg[a]], b);
	else if (segdepth[a] < segdepth[b]) return lca(a, segroot[seg[b]]);
	else return lca(segroot[seg[a]], segroot[seg[b]]);
}
int main () {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n-1; ++i) {
		scanf("%d%d", &a, &b);
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	count_child(0, -1);
	decomp(0, segcount, 0, 0);
	scanf("%d", &q);
	
	for (int i = 0, a, b; i < q; ++i) {
		scanf("%d%d", &a, &b);
		//printf("%d %d %d\n", height[a], height[b], lca(a, b));
		printf("%d\n", height[a] + height[b] - 2*height[lca(a, b)]);
	}
}

