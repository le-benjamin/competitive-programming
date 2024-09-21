/*
ID: b.le611
PROG: fence6
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

#define NMAX 105

int N;
vt<int> adjl[NMAX], adjr[NMAX];
int l[NMAX];
char side[NMAX][NMAX];
bool vis[NMAX];

int dfs(int u, char s) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int out = INT_MAX;
    if (s == 'R') {
        for (auto const& v : adjl[u])
            out = min(out, dfs(v, side[v][u])+l[u]);
    } else {
        for (auto const& v : adjr[u])
            out = min(out, dfs(v, side[v][u])+l[u]);
    }
    vis[u] = 0;

    return out;
}

int main() {
    setIO("fence6");

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, n1, n2; cin >> s >> l[s] >> n1 >> n2;
        for (int j = 0; j < n1; j++) {
            int t; cin >> t;
            adjl[s].pb(t);
            side[s][t] = 'L';
        }
        for (int j = 0; j < n2; j++) {
            int t; cin >> t;
            adjr[s].pb(t);
            side[s][t] = 'R';
        }
    }

    int best = INT_MAX;
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        best = min(best, dfs(i, 'L'));
    }
    cout << best << '\n';

    return 0;
}