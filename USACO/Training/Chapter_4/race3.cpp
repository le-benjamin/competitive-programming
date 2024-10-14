/*
ID: b.le611
PROG: race3
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

int n = 0;
vector<vector<int>> adj;

bool is_unavoidable(int x) {
    bool vis[55];
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& y : adj[cur]) {
            if (y == x) continue;
            if (y == n) return 0;
            if (!vis[y]) {
                vis[y] = 1;
                q.push(y);
            }
        }
    }

    return 1;
}

bool is_splitting(int x) {
    bool vis[2][55];
    memset(vis, 0, sizeof(vis));
    queue<int> q;

    q.push(0);
    vis[0][0] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& y : adj[cur]) {
            if (y == x) continue;
            if (y == n) return 0;
            if (!vis[0][y]) {
                vis[0][y] = 1;
                q.push(y);
            }
        }
    }

    q.push(x);
    vis[1][x] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& y : adj[cur]) {
            if (y == n) continue;
            if (vis[0][y]) return 0;
            if (!vis[1][y]) {
                vis[1][y] = 1;
                q.push(y);
            }
        }
    }

    return 1;
}


int main() {
    setIO("race3");

    
    for (int temp = 0; temp != -1; n++) {
        cin >> temp;
        if (temp != -1) adj.pb({});
        while (temp != -2 && temp != -1) {
            adj[n].pb(temp);
            cin >> temp;
        }
    } n--; n--;

    // find unavoidable points
    // for each point
        // do bfs from source excluding the point
        // if bfs does not reach sink, then unavoidable

    vector<int> unavoidable;
    for (int i = 1; i < n; i++) 
        if (is_unavoidable(i)) unavoidable.pb(i);
    
    // find splitting points
    // for each unavoidable point
        // determine if splitting point
            // do bfs from source to split point
            // do bfs from split point to sink
     
    vector<int> splitting;
    for (auto& x : unavoidable) {
        if (is_splitting(x)) splitting.pb(x);
    }

    cout << unavoidable.size();
    for (auto& x : unavoidable) cout << " " << x;
    cout << "\n";
    cout << splitting.size();
    for (auto& x : splitting) cout << " " << x;
    cout << "\n";

    return 0;
}