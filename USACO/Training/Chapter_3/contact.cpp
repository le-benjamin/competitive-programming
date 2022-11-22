/*
ID: b.le611
PROG: contact
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
auto cmp = [](string& a, string& b){
    if (sz(a) == sz(b)) { return a < b; } 
    return sz(a) < sz(b); 
};

int a, b, n;
string seq;
vt<pair<int, vt<string>>> freq; //f = freq, s[] = pattern


void solve() {
    int len = a-1;
    map<string, int> pat;

    while (++len <= b) {
        for (int i = 0; i <= sz(seq)-len; i++) {
            pat[seq.substr(i, len)] += 1;
        }
    }

    // temp map to group all values with same frequency
    map<int, vt<string>> temp; 

    EACH(x, pat) { temp[x.s].pb(x.f); }
    EACH(x, temp) { sort(all(x.s), cmp); freq.eb(x.f, x.s); }

    sort(all(freq), [&](auto& a, auto& b){ return a.f > b.f; });
}

int main() {
    setIO("contact");

    read(a, b, n); 

{
    string temp;
    while (getline(cin, temp)) { seq += temp; }
}

    solve();

    bool f1 = 0;
    FOR(sz(freq)) {
        if (i >= n) break;
        if (f1) print();
        f1 = 1;
        write(freq[i].f);
        FOR(j, sz(freq[i].s)) {
            if (j%6 == 0) print();
            write(freq[i].s[j]);
            if (j%6 != 5 && j < sz(freq[i].s)-1) write(' ');
        }
    }
    print();
    

    return 0;
}
