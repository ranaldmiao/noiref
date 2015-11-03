bool isPrime(int x) {
    if (x < 2) return false; //All primes are above 2
    else if (x == 2) return true; //If its 2, its a prime
    else if (x % 2 == 0) return false; //If its even (other than 2), its not a prime -> used for speedup 
    for (int i = 3; i <= x/i; i+=2) { //Trial divide all odd numbers > 2 up till the square root of x
        if (x % i == 0) return false; //If a factor is found, x is not prime
    }
    return true; //If no factors are found, x is a prime
}