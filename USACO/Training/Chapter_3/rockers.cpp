/*
ID: b.le611
PROG: rockers
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9+7;
const ll INF = 1e18;

void setIO(string name = "", int prec = 2) { // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec); // use cout instead of print() or write()
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
}

int n, t, m;
int a[25];

int main() {
    setIO("rockers");

    cin >> n >> t >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    // bruteforce
    int best = 0;
    for (int b = 1; b < 1<<n; b++) { // b = bitmask
        if (__builtin_popcount(b) <= best) continue; // bit on = song at that index that MUST be used
        int cur = 0, ind = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!(b&(1<<i))) continue;

            if (cur+a[i] <= t) cur += a[i];
            else {
                cur = a[i];
                ind++;
            }
            
            if (a[i] > t || ind >= m) { ok=0; break; } // check for invalid permutations
        }
        if (ok) best = __builtin_popcount(b);
    }
    cout << best << '\n';

    return 0;
}