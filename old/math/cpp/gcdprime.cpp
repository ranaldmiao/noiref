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