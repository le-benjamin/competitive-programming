/*
ID: b.le611
PROG: milk6
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

void setIO(string name = "", int prec = 2) { 
    // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
}

int n, m;

int maxFlow(int s, int e, int g[32][32]) {
    if (s == e) {
        return MOD;
    }
    int h[32][32];
    int pre[32]; 
    bool vis[32];
    int flow[32];
    int totalFlow = 0;
    int pathcap = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            h[i][j] = g[i][j];
        }
    }

    while (1) {
        fill(pre, pre+32, -1);
        fill(vis, vis+32, false);
        fill(flow, flow+32, 0);
        flow[s] = MOD;
        
        int mf = 0;
        int mfi = -1;

        while (1) {
            mf = 0;
            mfi = -1;
            for (int i = 0; i < n; i++) {
                if (flow[i] > mf && !vis[i]) {
                    mf = flow[i];
                    mfi = i;
                }
            }

            if (mfi == -1) {
                break;
            }
            if (mfi == e) {
                break;
            }

            vis[mfi] = true;
            for (int i = 0; i < n; i++) {
                if (h[mfi][i] == 0) {
                    continue;
                }
                if (flow[i] < min(mf, h[mfi][i])) {
                    pre[i] = mfi;
                    flow[i] = min(mf, h[mfi][i]);
                }
            }
        }

        if (mfi == -1) {
            break;
        }
        pathcap = flow[e];
        totalFlow += pathcap;

        int curi = e;
        while (curi != s) {
            int nexi = pre[curi];
            h[nexi][curi] -= pathcap;
            h[curi][nexi] += pathcap;
            curi = nexi;
        }
    }
    
    return totalFlow;
}

int main() {
    setIO("milk6");

    cin >> n >> m;

    int g[32][32];
    fill(&g[0][0], &g[0][0]+32*32, 0);
    vector<pair<int, pair<int, pair<int, int>>>> edges;
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        s--;
        e--;
        g[s][e] += c;
        edges.push_back(pair<int, pair<int, pair<int, int>>>(-c, pair<int, pair<int, int>>(i, pair<int,int>(s, e))));
    }

    sort(edges.begin(), edges.end());
    vector<int> routes;
    int mf = maxFlow(0, n-1, g), C = 0;
    for (int i = 0; i < m; i++) {
        int s, e, c, ri;
        s = edges[i].second.second.first;
        e = edges[i].second.second.second;
        c = -edges[i].first;
        ri = edges[i].second.first;
        g[s][e] -= c;
        int f = maxFlow(0, n-1, g);
        if (mf-f == c) {
            C += c;
            mf = f;
            routes.push_back(ri);
        } else {
            g[s][e] += c;
        }
    }

    cout << C << " " << routes.size() << "\n";
    sort(routes.begin(), routes.end());
    for (auto ri : routes) {
        cout << ri+1 << '\n';
    }

    return 0;
}