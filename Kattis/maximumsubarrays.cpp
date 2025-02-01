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

#define N 5005

ll dp[N];
ll pre[N];
ll a[N];

ll solve() {
    ll out = 0;

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < k; ++i) {
        out = -1e18;
        for (int j = i; j < n; ++j) {
            dp[j+1] = max(dp[j], pre[j]) + a[j+1];
            pre[j] = out;
            out = max(out, dp[j+1]);
        }
    }

    for (int i = 0; i < n; i++) cout << dp[i+1] << ' ';
    cout << '\n';

    for (int i = 0; i < n; i++) cout << pre[i+1] << ' ';
    cout << '\n';

    return out;
}

int main() {
    setIO("");

    cout << solve() << '\n';

    return 0;
}