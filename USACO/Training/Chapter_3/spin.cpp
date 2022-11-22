/*
ID: b.le611
PROG: spin
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
template<class T> string to_string(T& v) {
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

// this was a very messy solution 

// task variables, funcs, definitions
vt<pair<int, vt<pair<int, int>>>> wheels(5); // .f = speed, .s[i].f = start, .s[i].s = end
int minSpeed = MOD;

int lcm(int a, int b) { return (a*b)/__gcd(a,b); }

pair<int, int> merge(const pair<int, int>& a, const pair<int, int>& b) {
    pair<int, int> res = {-1, -1};

    if (a.f >= b.f && a.f <= b.s) {
        if (a.s <= b.s) res = {a.f%360, a.s%360};
        else res = {a.f%360, b.s%360};
    }
    else if (b.f >= a.f && b.f <= a.s) {
        if (b.s <= a.s) res = {b.f%360, b.s%360};
        else res = {b.f%360, a.s%360};
    }

    if (res.s < res.f) res.s += 360;
    
    return res;
}

string solve() {
    int time;

    for (time = 0; time < 360; time++) {
        vt<pair<int, int>> intervals;
        vt<vt<bool>> good;
        // run it a few times over to be safe lol
        FOR(a, 3) {            
            FOR(i, 5) {
                // update interval for time
                auto wheel = wheels[i];
                EACH(in, wheel.s) {
                    in.f = (in.f+time*wheel.f)%360;
                    in.s = (in.s+time*wheel.f)%360;

                    if (in.s < in.f) in.s += 360;
                }
                
                EACH(in, wheel.s) {
                    bool fits = false;
                    FOR(j, sz(intervals)) {
                        auto res = merge(in, intervals[j]);
                        if (res.f != -1) {fits = 1; intervals[j] = res; good[j][i] = 1; continue;}

                        res = merge({in.f+360, in.s+360} , intervals[j]);
                        if (res.f != -1) {fits = 1; intervals[j] = res; good[j][i] = 1; continue;}

                        res = merge(in, {intervals[j].f+360, intervals[j].s+360});
                        if (res.f != -1) {fits = 1; intervals[j] = res; good[j][i] = 1; continue;}
                    }
                    if (!fits) { intervals.pb(in); good.pb(vt<bool>(5, 0)); good.back()[i] = 1;}
                }
            }
        }
        EACH(x, good) {
            if (find(all(x), false) == x.end()) return to_string(time);
        }
    }

    return "none";
}

int main() {
    setIO("spin");

    EACH(x, wheels) {
        int speed, w;
        read(speed, w);
        x.f = speed;
        minSpeed = min(minSpeed, speed);
        FOR(w) {
            int start, ext;
            read(start, ext);
            x.s.eb(start, start+ext);
        }
    }
    print(solve());

    return 0;
}
