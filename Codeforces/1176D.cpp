#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int maxn = 2750131;
vt<int> primes;    // index of val in p
vt<int> divisors;

void sieve(ll n) {
    primes.resize(n+1, 1);
    divisors.resize(n+1, -1);
    int index = 1;
    for (ll i = 2; i <= n; i++) {
        if (primes[i] > 0) {
            primes[i] = index++;
            divisors[i] = -1;
            for (ll j = i*i; j <= n; j += i) primes[j] = -1;
        }
        else {
            int val = 1;
            for (ll j = 2; j*j <= i && val == 1; j++) {
                if (i/j * j == i) {
                    val = i/j;
                }
            }
            divisors[i] = val;
        }
    }
}


int main() {
    sieve(maxn);

    int n;
    scanf("%d\n", &n);
    map<int, int> b;
    vt<int> a;
    int m = 0;

    for (int i = 0; i < n*2; i++) {
        int temp;
        scanf("%d", &temp);
        b[temp]++;
        m = max(m, temp);
    }

    for (int i = m; i >= 0; i--) {
        while (b[i] > 0) {
            if (primes[i] > 0) {
                a.pb(primes[i]);
                b[primes[i]]--;
            } else {
                a.pb(i);
                b[divisors[i]]--;
            }
            b[i]--;
        }
    }

    for (auto& x : a) printf("%d ", x);

    return 0;
}
