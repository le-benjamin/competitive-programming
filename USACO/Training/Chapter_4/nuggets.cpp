/*
ID: b.le611
PROG: nuggets
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

#define LIM (256*256 - (256+256))
int MAX = 1e6;

int N;
vt<int> v;

int main() {
    setIO("nuggets");

    cin >> N;
    v.resize(N);
    for (auto& x : v) cin >> x;
    sort(all(v));

    bool dp[MAX+1]; dp[0] = 1;
    int best = 0;
    for (int i = 0; i < MAX+1; i++) {
        for (auto& x : v) {
            if (x > i) break;
            dp[i] |= dp[i-x];
        }
        if (!dp[i]) best = i;
    }

    cout << (best > LIM ? 0 : best) << '\n';


    return 0;
}