/*
ID: b.le611
PROG: ratios
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

template<typename h0, typename h1, typename...Tl>
constexpr auto max(h0 &&hf, h1 &&hs, Tl &&... tl) {
    if constexpr (sizeof...(tl) == 0)
        return hf > hs ? hf : hs;
    else return max(max(hf, hs), tl...);
}

template<typename h0, typename h1, typename...Tl>
constexpr auto min(h0 &&hf, h1 &&hs, Tl &&... tl) {
    if constexpr (sizeof...(tl) == 0)
        return hf < hs ? hf : hs;
    else return min(min(hf, hs), tl...);
}

// to_strings
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

// IO
void setIO(string name = "", int prec = 2) { // lim prec = 15
    // cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec); // use cout instead of print() or write()
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
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
vt<ll> goal(3, 0);
vt<vt<ll>> feeds(3, vt<ll>(3, 0));
int bestSum = MOD, bestMultiple = 0;
vt<int> best(3, MOD);


bool check(int a, int b, int c) {
    if (a+b+c > bestSum) return false;

    int g0 = feeds[0][0]*a + feeds[1][0]*b + feeds[2][0]*c;
    int g1 = feeds[0][1]*a + feeds[1][1]*b + feeds[2][1]*c;
    int g2 = feeds[0][2]*a + feeds[1][2]*b + feeds[2][2]*c;

    if (g0 == 0 && goal[0] != 0) return false;
    if (g1 == 0 && goal[1] != 0) return false;
    if (g2 == 0 && goal[2] != 0) return false;

    if (g0 != 0 && goal[0] == 0) return false;
    if (g1 != 0 && goal[1] == 0) return false;
    if (g2 != 0 && goal[2] == 0) return false;

    if ((goal[0] == 0 || g0%goal[0] == 0) && (goal[1] == 0 || g1%goal[1] == 0) && (goal[2] == 0 || g2%goal[2] == 0)) {
        int q0 = -1, q1 = -1, q2 = -1;

        if (goal[0] != 0) q0 = g0/goal[0];
        if (goal[1] != 0) q1 = g1/goal[1];
        if (goal[2] != 0) q2 = g2/goal[2];

        if (q0 == -1) q0 = max(q0, q1, q2);
        if (q1 == -1) q1 = max(q0, q1, q2);
        if (q2 == -1) q2 = max(q0, q1, q2);

        if (q0 != q1 || q0 != q2 || q1 != q2) return false;

        bestSum = a+b+c;
        best[0] = a;
        best[1] = b;
        best[2] = c;

        bestMultiple = q1;
        
        return true;
    }
    return false;
}

int main() {
    setIO("ratios");

    read(goal);
    read(feeds);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                check(i, j, k);
            }
        }
    }

    if (bestMultiple == 0) print("NONE");
    else print(best, bestMultiple);


    return 0;
}
