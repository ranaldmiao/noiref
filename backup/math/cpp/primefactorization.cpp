vector<int> primeList;

vector<int> primeFactorize(int X) {
    vector<int> result;
    for (vector<int>::iterator it = primeList.begin(); it != primeList.end(); ++it) {
        if (*it > X/(*it)) break; //Check if prime exceeds sqrt(X)
        while (X % *it == 0) { //When it is divisible, divide as many times as possible
            X /= *it; 
            result.push_back(*it);
        }
    }
    if (X != 1) result.push_back(X); //The last factor above sqrt(X)
    return result;
}
