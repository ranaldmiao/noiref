#include <cstdio>
using namespace std;
int n, a[1000005], counters[1000005];
int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &a[i]);
	/* assuming the numbers are from 0 to 1million */
	for (int i = 0; i < n; ++i) {
		counters[a[i]]++;
	} 
	/* Runs in O( N + 1000000 ) where 1mil is the max element */
	for (int i = 0; i <= 1000000; ++i) {
		for (int k = 0; k < counters[i]; ++k) {
			printf("%d\n", i);
		}
	}
}

