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

void setIO(string name = "", int prec = 2) { // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec); // use cout instead of print() or write()
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
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

void solve() {

    int n; read(n);
    
    for(int a = 0; a < n; a++) {
        string name; read(name);
        int r, c; read(r, c);

        int pc = 0, ac = 0;

        vt<vt<short>> perim(r, vt<short>(c, 0)); // 1 = perimeter cell, -1 = shape cell
        for (int i = 0; i < r; i++) {
            string s; read(s);
            for (int j = 0; j < c; j++) {
                char c = s[j];
                if (c == '#') {
                    ac++;
                    perim[i][j] = -1;
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if (i+k >= 0 && i+k < r && j+l >= 0 && j+l < c && perim[i+k][j+l] != -1 && perim[i+k][j+l] != 1) {
                                perim[i+k][j+l] = 1;
                                pc++;
                            }
                        }
                    }

                }
            }
        }
        print(name, ac, pc);
    }
    print();
}

int main() {
    setIO("data");
    
    int t; read(t);
    while (t--) solve();

    return 0;
}
