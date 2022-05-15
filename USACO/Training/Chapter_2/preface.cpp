/*
ID: b.le611
PROG: preface
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
#define MAX_N 3500
map<int, string> m;
char order[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int N;

string a2r(int a) {
    string res = "";
    for (auto i = m.rbegin(); i != m.rend(); i++) {
        while (a >= i->first) {
            res += i->second;
            a -= i->first;
        }
    }
    return res;
}

void solve() {

}

int main() {
    setIO("preface");
    
    // init m, map arabic to roman numerals
    m[1000] = "M"; m[900] = "CM"; m[500] = "D"; m[400] = "CD";
    m[100] = "C"; m[90] = "XC"; m[50] = "L"; m[40] = "XL"; 
    m[10] = "X"; m[9] = "IX"; m[5] = "V"; m[4] = "IV"; m[1] = "I";

    read(N);

    map<char, int> counts;

    FOR(i, 1, N+1) {
        string r = a2r(i);
        EACH(c, r)
            counts[c]++;
    }

    EACH(c, order) {
        if (counts.find(c) != counts.end()) {
            print(c, counts[c]);
        }
    }


    return 0;
}
