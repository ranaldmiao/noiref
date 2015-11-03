#include <bits/stdc++.h>
using namespace std;
#define N 1000000
bitset<N+1> isPrime;
vector<int> primeList;
vector<int> primeFactorize(int X) {
    vector<int> result;
    for (vector<int>::iterator it = primeList.begin(); it != primeList.end(); ++it) {
        if (*it > X/(*it)) break;
        while (X % *it == 0) {
            X /= *it; 
            result.push_back(*it);
        }
    }
    if (X != 1) result.push_back(X);
    return result;
}
int gcd (int a, int b) {
    vector<int> factorized_a = primeFactorize(a);
    vector<int> factorized_b = primeFactorize(b);
    int i = 0, j = 0, result = 1;
    while (i < factorized_a.size() && j < factorized_b.size()) {
        if (factorized_a[i] < factorized_b[j]) ++i;
        else if (factorized_a[i] > factorized_b[j]) ++j;
        else {
            result *= factorized_a[i];
            ++i, ++j;
        }
    }
    return result;
}
int main () {
	isPrime.reset(); isPrime.flip();
	isPrime[0] = isPrime[1] = 0;
	primeList.push_back(2);
	for (int i = 4; i <= N; i+=2) isPrime[i] = 0;
	for (int i = 3; i <= N; i+=2) {
	    if (!isPrime[i]) continue;
	    primeList.push_back(i);
	    for (int j = i; j <= N/i; ++j) isPrime[i*j] = 0;  
	}
	while (1) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
}
