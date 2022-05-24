/*
ID: b.le611
PROG: ttwo
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

struct coord
{
    int x;
    int y;
    coord() { x = 0; y = 0; }
    coord(int _x, int _y) { x = _x; y = _y; };
};

int fd = 0, cd = 0; // direction, 0 = north, 1 = east, etc
coord fc, cc;

vt<vt<bool>> graph(10, vt<bool>(10, false));

void step() { // helper function to simulate one minute passing
    int dfx = fc.x, dfy = fc.y;
    switch (fd) {
        case 0 : dfy--; break;
        case 1 : dfx++; break;
        case 2 : dfy++; break;
        case 3 : dfx--; break;
    }
    if (dfy == -1 || dfx == -1 || dfy == 10 || dfx == 10 || graph[dfx][dfy]) fd = (fd+1)%4;
    else { fc.x = dfx; fc.y = dfy; }

    int dcx = cc.x, dcy = cc.y;
    switch (cd) {
        case 0 : dcy--; break;
        case 1 : dcx++; break;
        case 2 : dcy++; break;
        case 3 : dcx--; break;
    }
    if (dcy < 0 || dcx < 0 || dcy > 9 || dcx > 9 || graph[dcx][dcy]) cd = (cd+1)%4;
    else { cc.x = dcx; cc.y = dcy; }
}

int solve() {
    int minutes = 0;

    while ((fc.x != cc.x || fc.y != cc.y) && minutes++ < 10000)
        step();

    return (minutes >= 10000 ? 0 : minutes);
}

int main() {
    setIO("ttwo");

    FOR(i, 10) {
        string st;
        read(st);
        FOR(j, 10) 
            if (st[j] == '*')
                graph[j][i] = true;
            else 
                if (st[j] == 'F')
                    fc = {j, i};
                else if (st[j] == 'C')
                    cc = {j, i};
    }

    print(solve());

    return 0;
}
