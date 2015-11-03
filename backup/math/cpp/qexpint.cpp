int qexp(int A, int B, int M) {
    if (B == 0) return 1; //A^0 = 1 for all A
    long long half = qexp(A, B/2, M); //Note that B/2 is rounded down, this will be compensated later
    half *= half; //Long long is required to ensure this operation does not overflow when M is close to 2^31
    half %= M;
    if (B%2==1) half += A;  //Compensate the 'round down' of B/2 when B is odd
    return half%M;
}