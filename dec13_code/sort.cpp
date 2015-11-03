#include <algorithm>
#include <cstdio>
using namespace std;
int n, a[1000005], b[1000005], order[1000005];
bool cmp (int x, int y) {
	/* number in first array*/
	if (a[x] != a[y]) return a[x] < a[y];
	/* number in second array*/
	if (b[x] != b[y]) return b[x] < b[y];
	/* return based on index */
	return x < y;
}
int main () {
	scanf("%d", &n); /* n = size of array/number of num to sort*/
	for (int i = 0; i < n; ++i) 
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &b[i]);
	/* initialize the 'order' array */
	for (int i = 0; i < n; ++i)
		order[i] = i;
	/* sort(begin, end, comparator function */
	/* sort the 'order' array, not the original array */
	sort(order, order+n, cmp);
	for (int i = 0; i < n; ++i) {
		int it = order[i]; //get the first in order
		printf("%d %d\n", a[it], b[it]);
	}
}

