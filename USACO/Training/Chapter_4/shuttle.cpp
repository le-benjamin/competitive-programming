/*
ID: b.le611
PROG: shuttle
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

vt<int> bfs() {
    string initial = string(n, 'W') + ' ' + string(n, 'B');
    string goal = string(n, 'B') + ' ' + string(n, 'W');
    unordered_set<string> vis;
    queue<tuple<string, int, vt<int>>> q;
    vis.insert(initial);
    q.emplace(initial, n, vt<int>());

    while (!q.empty()) {
        string s;
        int i;
        vt<int> v;
        tie(s, i, v) = q.front();
        q.pop();
        if (s == goal) return v;

        if (i-2 >= 0 && s[i-2] == 'W' && s[i-1] == 'B') {
            string sn(s);
            sn[i] = 'W';
            sn[i-2] = ' ';
            vt<int> vn(v);
            vn.push_back(i-2);
            if (!vis.count(sn)) q.emplace(sn, i-2, vn);
            vis.insert(sn);
        }
        if (i-1 >= 0 && s[i-1] == 'W') {
            string sn(s);
            sn[i] = 'W';
            sn[i-1] = ' ';
            vt<int> vn(v);
            vn.push_back(i-1);
            if (!vis.count(sn)) q.emplace(sn, i-1, vn);
            vis.insert(sn);
        }
        if (i+1 <= n*2 && s[i+1] == 'B') {
            string sn(s);
            sn[i] = 'B';
            sn[i+1] = ' ';
            vt<int> vn(v);
            vn.push_back(i+1);
            if (!vis.count(sn)) q.emplace(sn, i+1, vn);
            vis.insert(sn);
        }
        if (i+2 <= n*2 && s[i+2] == 'B' && s[i+1] == 'W') {
            string sn(s);
            sn[i] = 'B';
            sn[i+2] = ' ';
            vt<int> vn(v);
            vn.push_back(i+2);
            if (!vis.count(sn)) q.emplace(sn, i+2, vn);
            vis.insert(sn);
        }

    }

    return {};
}

int main() {
    setIO("shuttle");

    cin >> n;

    vt<int> out = bfs();
    
    for (int i = 0; i < out.size(); i++) {
        if (i%20 != 0) cout << ' ';
        cout << out[i]+1;
        if (i == out.size()-1 || i%20 == 19) cout << '\n';
    }

    return 0;
}