/*
ID: b.le611
PROG: camelot
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

#define f first
#define s second

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

int R, C;
int dist[30][30][30][30];
vt<pair<int, int>> knights;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    dist[sr][sc][sr][sc] = 0;

    int r, c;
    while (!q.empty()) {
        tie(r,c) = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (dist[sr][sc][nr][nc] != -1) continue;

            dist[sr][sc][nr][nc] = dist[sr][sc][r][c] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    setIO("camelot");

    memset(dist, -1, sizeof(dist));

    cin >> R >> C;

    // king
    int kr, kc;
    int r; char c;
    cin >> c >> r;
    kr = r-1; kc = c-'A';

    while (cin >> c >> r) knights.eb(r-1, c-'A');
    
    if (knights.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bfs(i, j);
        }
    }

    int best = INT_MAX;
    for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
        int sum = 0;
        for (auto k : knights) {
            if (dist[k.f][k.s][i][j] == -1) {
                sum = INT_MAX;
                break;
            } else sum += dist[k.f][k.s][i][j];
        }

        if (sum == INT_MAX) continue;
        
        int kd = max(abs(i-kr),abs(j-kc)); // king can move diagonally, not manhattan dist lol

        for (int x = max(0, kr-2); x < min(R, kr+3); x++) 
        for (int y = max(0, kc-2); y < min(C, kc+3); y++) {
            for (auto k : knights) 
                if (dist[k.f][k.s][x][y] != -1 && dist[x][y][i][j] != -1)
                    kd = min(kd, max(abs(kr-x), abs(kc-y))+dist[k.f][k.s][x][y]+dist[x][y][i][j]-dist[k.f][k.s][i][j]);
        }

        best = min(best, sum+kd);
    }

    cout << best << '\n';

    return 0;
}