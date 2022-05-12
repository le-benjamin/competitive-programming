/*
ID: b.le611
PROG: milk3
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
#define MAX_CAP 21
vt<int> vals = {0, 0, 0};
vt<int> caps = {0, 0, 0};
vt<int> amts;
bool memo[MAX_CAP][MAX_CAP][MAX_CAP] = {};



void search() { // 0 = a, 1 = b, 2 = c
    if (memo[vals[0]][vals[1]][vals[2]]) return;
    memo[vals[0]][vals[1]][vals[2]] = true;
    int ta = vals[0], tb = vals[1], tc = vals[2];
    FOR(i, 3) {
        FOR(j, 2) {
            vals[0] = ta; vals[1] = tb; vals[2] = tc;
            int ind = (i+j+1)%3;
            vals[ind] += vals[i];
            vals[i] -= vals[i];
            if (vals[ind] > caps[ind]) {
                vals[i] += vals[ind]-caps[ind];
                vals[ind] = caps[ind];
            }
            if (vals[0] == 0 && (amts.empty() || *lower_bound(all(amts), vals[2]) != vals[2])) amts.push_back(vals[2]);
            sort(all(amts));
            search();
        }
    }
}


int main() {
    setIO("milk3");

    read(caps);
    vals[2] = caps[2];
    
    search();

    print(amts);

    return 0;
}
