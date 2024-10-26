/*
ID: b.le611
PROG: lgame
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
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec); // use cout instead of print() or write()
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
}

int val[] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
unordered_set<string> dict;
string s;
vector<string> best;
int mx = -1;

int score(string x) {
    int out = accumulate(all(x), 0, [](int p, char c){ 
        return p+(isalpha(c) ? val[c-'a'] : 0); 
    });

    return out;
}

vector<string> gen(string x) {
    vector<string> out = {""};
    if (x.length() < 3) return out;

    if (dict.count(x)) {
        out.clear();
        out.pb(x);
    } 

    for (int i = 1; i < x.length(); i++) {
        vector<string> l = gen(x.substr(0, i));
        vector<string> r = gen(x.substr(i));

        int sc = score(l[0] + r[0]);
        int sco = score(out[0]);

        if (sc < sco) continue;

        if (out[0] == "" || sco < sc) out.clear();
        for (auto a : l) {
            for (auto b : r) {
                out.pb((a < b ? a : b) + (sz(a) && sz(b) ? " " : "") + (a < b ? b : a));
            }
        }
    }

    return out;
}

int main() {
    setIO("lgame");
    cin >> s;
    freopen("lgame.dict", "r", stdin);
    for (string x; cin >> x && x != "."; ) dict.insert(x);

    set<string> out = {""};
    
    sort(all(s));
    do {
        vector<string> temp = gen(s);
        int sct = score(temp[0]);

        if (sct < mx) continue;
        else if (mx < sct) out.clear();
        mx = sct;

        for (auto x : temp) out.insert(x);
    } while(next_permutation(all(s)));

    cout << mx << '\n';
    for (auto x : out) cout << x << '\n';

    return 0;
}