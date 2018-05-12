struct SparseTable {
    vector<vector<int> > ST;
    int N, K;
    SparseTable(int _N, int a[]): N(_N) {
        K = MSB(N);
        ST.resize(K);
        ST[0] = vector<int>(a, a+N);
        for (int k = 1; k < K; ++k) 
            for (int i = 0; i+(1<<k) <= N; ++i) 
                ST[k].push_back( min(ST[k-1][i], ST[k-1][i+(1<<(k-1))]) ); //min
    }
    
    /* returns most significant bit of an integer */
    inline int MSB(unsigned int x) { return 32-__builtin_clz(x); }
    
    /* Min of range (x, x + 2^k-1) and (y-2^k+1, y) */
    int query(int x, int y) {
        int k = MSB(y-x+1) - 1;
        return min(ST[k][x], ST[k][y-(1<<k)+1]);            //min
    }
    
};