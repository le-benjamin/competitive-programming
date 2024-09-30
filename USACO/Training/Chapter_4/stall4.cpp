/*
ID: b.le611
PROG: stall4
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

int N, M;
bool vis[405];
int mat[405][405];
int pre[405];

int solve() {
    int out = 0;
    const int sink = N+M+1;
    int pathCap = 1;

    while (pathCap) {
        memset(vis, 0, sizeof(vis));
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v = 1; v <= sink; v++) {
                if (!vis[v] && mat[u][v] > 0) {
                    vis[v] = 1;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }

        pathCap = 0;
        int cur = sink;

        while (pre[cur] != -1) {
            int prev = pre[cur];
            pathCap = min(pathCap, mat[prev][cur]);
            if (pathCap == 0) pathCap = mat[prev][cur];
            cur = prev;
        }

        cur = sink;
        while (pre[cur] != -1) {
            int prev = pre[cur];
            mat[prev][cur] -= pathCap;
            mat[cur][prev] += pathCap;
            cur = prev;
        }

        out += pathCap;
    }

    return out;
}

int main() {
    setIO("stall4");

    cin >> N >> M;

    memset(mat, 0, sizeof(mat));

    for (int i = 1; i <= N; i++) {
        mat[0][i] = 1;
        int s; cin >> s;
        while (s--) {
            int x; cin >> x;
            x += N;
            mat[i][x] = 1;
            mat[x][N+M+1] = 1;
        }
    }

    cout << solve() << '\n';

    return 0;
}