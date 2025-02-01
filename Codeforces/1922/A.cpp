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



void solve() {
    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;

    bool exists = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] != a[i] && c[i] != b[i]) {
            exists = 1;
            break;
        }
    }

    cout << (exists ? "YES" : "NO") << '\n';
}

int main() {
    setIO("");

    int tc; cin >> tc;
    while (tc--) 
        solve();


    return 0;
}