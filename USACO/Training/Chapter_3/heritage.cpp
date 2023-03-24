/*
ID: b.le611
PROG: heritage
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

string in, pre, post = "";
int i = 0;

void recurse(int l, int r) {
    if (l > r) { i--; return; }
    if (l == r) { post += in[l]; return; }

    int c = 0;
    for (; in[c] != pre[i]; c++);
    i++;
    recurse(l, c-1);
    i++;
    recurse(c+1, r);

    post += in[c];
}

int main() {
    setIO("heritage");

    cin >> in >> pre;
    recurse(0, pre.size()-1);
    cout << post << '\n';

    return 0;
}