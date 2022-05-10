/*
ID: b.le611
PROG: skidesign
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

void setIO(string name = "", int prec = 15) {
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); }
}

const int MOD = 1e9+7;
const ll  INF = 1e18;


// task variables, funcs, definitions
#define MAX_H 17

int n;
vt<ll> heights;

ll solve() {
    ll ans = INF; 

    ll h = heights.back()-heights.front()-MAX_H;
    if (h <= 0) return 0;
    ll dl1 = h/2+heights.front(), dr1 = heights.back()-ceil(h/2.0);
    ll sum = INF, dl2, dr2;
    int i; // declare outside of for so that init statement does everything
    for (i = 1, dl2 = dl1, dr2 = dr1; sum <= ans && dr2 <= heights.back(); i++, dl2++, dr2++) { // right
        ans = min(ans, sum); // min() is not strictly necessary, just for clarity
        sum = 0;
        for (auto it = heights.begin(); it < upper_bound(all(heights), dl2); it++) sum += (dl2-(*it))*(dl2-(*it));
        for (auto it = upper_bound(all(heights), dr2); it < heights.end(); it++)   sum += (*it-dr2)  *  (*it-dr2);
    }
    for (i = 1, dl2 = dl1, dr2 = dr1; sum <= ans && dl2 >= 0; i++, dl2--, dr2--) { // left
        ans = min(ans, sum);
        print(sum);
        sum = 0;
        for (auto it = heights.begin(); it < upper_bound(all(heights), dl2); it++) sum += (dl2-(*it))*(dl2-(*it));
        for (auto it = upper_bound(all(heights), dr2); it < heights.end(); it++)   sum += (*it-dr2)  *  (*it-dr2);
    }

    return ans;
}

int main() {
    setIO("skidesign");

    read(n);
    heights.resize(n, 0);
    read(heights);
    sort(all(heights));

    ll ans = solve();
    print(ans);

    return 0;
}
