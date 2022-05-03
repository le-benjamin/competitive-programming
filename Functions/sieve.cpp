void sieve(int n) {
    bool m[n+1] = {1};
    vt<int> primes;
    primes.pb(1);

    for (int i = 2; i*i <= n; i++) {
        if (m[i]) {
            primes.pb(i);
            for (int j = i*i; j <= n; j += i) primes[j] = 0;
        }
    }
    
}