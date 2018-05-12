#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M;
ll qexp (ll b, ll e) { //quick exponentiation (see below)
	if (e == 0) return 1;
	if (e == 1) return b%M;
	ll h = qexp(b, e/2);
	h *= h;
	h %= M;
	if (e%2 == 0) return h;
	return (h*b)%M;
}
bool isPrime(long long int N) {
	if (N <= 1) return 0;
	if (N <= 3) return 1;
	if (N == 4) return 0;
	ll s = (N-1)&(1-N), d = (N-1)/s;
	M = N;
	for (int i = 0, K = 30; i < K; ++i) {
	    ll witness = rand()%(N-4) + 2;  //generate random witness between [2, N-2]
		ll a = qexp(witness, d);
		if (a == 1 || a == N-1) continue;
		bool pass = 1;
		for (ll k = 1; k < s && pass; k<<=1) {
			a*=a;
			a%=N;
			if (a == N-1) pass = false;
		}
		if (pass) return 0; /* not a prime due to witness */
	}
	return 1;
}