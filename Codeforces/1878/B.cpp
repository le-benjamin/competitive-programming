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

vt<int> out = {2, 3};

void solve() {
    int n; cin >> n;

    while (out.size() < n) {
        int t = out.back() + 1;
        while ((3*t) % (out[out.size()-1]+out[out.size()-2]) == 0) t++;
        out.pb(t);
    }

    for (int i = 0; i < n; i++) {
        cout << out[i] << " \n"[i==n-1];
    }
}

int main() {
    setIO("");

    int tc; cin >> tc;
    while (tc--) 
        solve();


    return 0;
}