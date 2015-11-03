bitset<N+1> isPrime;
vector<int> primeList;
/* Initializing every number above 1 to be prime */
isPrime.reset();
isPrime.flip();
isPrime[0] = isPrime[1] = 0;

/* Cancel all multiples of 2 (Speedup) */
primeList.push_back(2);
for (int i = 4; i <= N; i+=2) isPrime[i] = 0;

/* Main sieve */
for (int i = 3; i <= N; i+=2) {
    if (!isPrime[i]) continue;
    primeList.push_back(i);
    /* Cancel all multiples of primes. Any multiple < i*i will already be cancelled by an earlier prime */
    for (int j = i; j <= N/i; ++j) isPrime[i*j] = 0;  
}
