#include <cstdio>
using namespace std;
/* dun look here */
int n, a[1000005], tmp[1000005];
void mergesort (int s, int e) {
	if (e-s <= 1) return;
	int h = (e+s)/2;
	mergesort(s, h); /* 'sort' half */
	mergesort(h, e); /* 'sort' another half*/
	/* The smallest element of both halves
	is either the smallest of the first
	is either the smallest of the first
	half or the smallest of the second half
	*/
	int x = s, y = h, z = s;
	while (x < h && y < e) {
		if (a[x] < a[y]) {
			tmp[z] = a[x];
			z++, x++;
		}
		else {
			tmp[z] = a[y];
			z++, y++;
		}
	}
	while (x < h) {
		tmp[z] = a[x];
		z++, x++;
	}
	while (y < e) {
		tmp[z] = a[y];
		z++, y++;
	}
	/* copy it back */
	for (int i = s; i < e; ++i)
		a[i] = tmp[i];
	
}
int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
		
	mergesort(0, n);
	
	for (int i = 0; i < n; ++i)
		printf("%d\n", a[i]);
}

