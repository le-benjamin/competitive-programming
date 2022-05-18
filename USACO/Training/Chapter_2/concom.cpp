/*
ID: b.le611
PROG: concom
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define ar array

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()

#define f first
#define s second

#define CSTR(n) ((char*)(malloc(sizeof(char)*n)))

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

const int MOD = 1e9+7;
const ll INF = 1e18;

void setIO(string name = "", int prec = 2) { // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); }
}

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f) res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class T> void read(T& x) { cin >> x; }
void read(double& d) { string t; read(t); d=stod(t); } // db & ld are special
void read(ld& d) { string t; read(t); d=stold(t); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }
template<class A> void read(vt<A>& x) { EACH(a, x) read(a); }

template<class A> void write(A x) { cout << to_string(x); }
template<class H, class... T> void write(const H& h, const T&... t) { write(h); write(t...); }
void print() { write("\n"); }
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

// task variables, funcs, definitions
#define MAX_N 101
int n;
vt<vt<int>> connected(MAX_N, vt<int>(MAX_N, 0)); // a | b  -> percentage
vt<vt<int>> owned(MAX_N);
vt<bitset<MAX_N>> bs(MAX_N);

void solve() {
    bool changed = 1;
    while (changed) {
        changed = 0;
        FOR(i, 1, MAX_N) {
            vt<int> percents(MAX_N, 0);
            FOR(j, 1, MAX_N) {
                if (connected[i][j] == 100) {
                    FOR(k, 1, MAX_N) {
                        if (connected[i][k] > 50 || connected[j][k] > 50) {
                            if (!bs[i][k]) { 
                                if (i != k)
                                    owned[i].pb(k);
                                bs[i][k] = 1;
                                changed = 1;
                            }
                            if (!bs[j][k]) {
                                if (j != k)
                                    owned[j].pb(k);
                                bs[j][k] = 1;
                                changed = 1;
                            }
                        }
                    }
                    sort(all(owned[i]));
                    sort(all(owned[j]));
                }
                if (connected[i][j] > 50 && !bs[i][j] && i != j) {
                    owned[i].pb(j);
                    sort(all(owned[i]));
                    bs[i][j] = 1; 
                    changed = 1; 
                }
                if (!bs[i][j]) continue;
                FOR(k, 1, MAX_N)
                    percents[k] += connected[j][k];
            }
            FOR(j, 1, MAX_N) {
                if (percents[j] > 50 && !bs[i][j] && i != j) {
                    owned[i].pb(j);
                    sort(all(owned[i]));
                    bs[i][j] = 1;
                    changed = 1;
                }
            }
        }
    }
}

int main() {
    setIO("concom");

    read(n);
    
    FOR(m, n) {
        int i, j, p;
        read(i, j, p);
        if (i != j)
            connected[i][j] = p;
    }
    
    solve();


    FOR(i, 1, MAX_N) {
        if (!sz(owned[i])) continue;
        EACH(j, owned[i])
            print(i, j);
    }


    return 0;
}
