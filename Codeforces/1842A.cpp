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
    int n, m; cin >> n >> m;
    vt<ll> tsondu(n), tenzing(m);
    for (auto& t : tsondu) cin >> t;
    for (auto& t : tenzing) cin >> t;

    ll tsonduScore = accumulate(tsondu.begin(), tsondu.end(), 0ll), tenzingScore = accumulate(tenzing.begin(), tenzing.end(), 0ll);

    if (tsonduScore > tenzingScore) cout << "Tsondu\n";
    else if (tsonduScore < tenzingScore) cout << "Tenzing\n";
    else cout << "Draw\n";
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
