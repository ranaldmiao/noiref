#include <bits/stdc++.h>
using namespace std;
#define BIT 18
typedef long long ll;
int a[100005], n, m;
set<int> off[BIT];
ll ans = 0;
ll sum(int k, int pos) {
	set<int>::iterator lit = off[k].upper_bound(pos);
	set<int>::iterator uit = lit--;
	ll num = (ll) ((*uit)-pos);
	num *= (ll) (pos-(*lit));
	num *= (1ll<<k);
	return num;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int k = 0; k < BIT; ++k) off[k].insert(-1);
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		a[i] = x;
		for (int k = 0; k < BIT; ++k) {
			if (x & (1<<k)) {
				off[k].insert(i+1);
				ans += sum(k, i);
				off[k].erase(i+1);
			}
			else off[k].insert(i);
		}
	}
	for (int k = 0; k < BIT; ++k) off[k].insert(n);
	while (m--) {
		int x, v;
		scanf("%d%d", &x, &v);
		--x;
		for (int k = 0; k < BIT; ++k) {
			if ( ((a[x])&(1<<k)) == (v&(1<<k)) ) continue;
			if ( v&(1<<k) ) {
				off[k].erase(x);
				ans += sum(k, x);
			}
			else {
				ans -= sum(k, x);
				off[k].insert(x);
			}
		}
		a[x] = v;
		printf("%I64d\n", ans);
	}
}

