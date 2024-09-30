/*
ID: b.le611
PROG: ditch
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
int mat[205][205];
int pre[205];
int flow[205];
bool vis[205];

int solve() {
    int out = 0;

    while (1) {
        memset(pre, -1, sizeof(pre));
        memset(flow, 0, sizeof(flow));
        memset(vis, false, sizeof(vis));
        
        flow[1] = MOD;

        int maxFlow = 0, maxLoc = -1;

        while (1) {
            maxFlow = 0, maxLoc = -1;
            for (int i = 1; i <= M; i++) {
                if (flow[i] > maxFlow && !vis[i]) {
                    maxFlow = flow[i];
                    maxLoc = i;
                }
            }
            if (maxLoc == -1 || maxLoc == M) break;
            vis[maxLoc] = true;

            for (int i = 1; i <= M; i++) {
                if (mat[maxLoc][i] == 0) continue;
                if (flow[i] < min(maxFlow, mat[maxLoc][i])) {
                    pre[i] = maxLoc;
                    flow[i] = min(maxFlow, mat[maxLoc][i]);
                }
            }
        }

        if (maxLoc == -1) break;

        int pathCap = flow[M];
        out += pathCap;

        int cur = M;

        while (cur != 1) {
            int next = pre[cur];
            mat[next][cur] -= pathCap;
            mat[cur][next] += pathCap;
            cur = next;
        }
    }


    return out;
}

int main() {
    setIO("ditch");

    memset(mat, 0, sizeof(mat));

    cin >> N >> M;
    for (int i = 0, s, e, c; i < N; i++) {
        cin >> s >> e >> c;
        mat[s][e] += c; 
    }
    cout << solve() << '\n';

    return 0;
}