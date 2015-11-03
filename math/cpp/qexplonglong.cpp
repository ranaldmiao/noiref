long long qmult(long long X, long long Y, long long M) {
    if (Y == 0) return 0; //Y*0 = 0
    long long half = qmult(X, Y/2, M);
    half += half;
    half %= M;
    if (Y % 2==1) half += half;
    return half%=M;
}
long long qexp(long long A, long long B, long long M) {
    if (B == 0) return 1; //A^0 = 1 for all A
    long long half = qexp(A, B/2, M); //Note that B/2 is rounded down, this will be compensated later
    half = qmult(half, half, M); //qmult is required to ensure this operation does not overflow when M is close to 2^62
    half %= M;
    if (B%2==1) half += A%M;  //Compensate the 'round down' of B/2 when B is odd
    return half%M;
}