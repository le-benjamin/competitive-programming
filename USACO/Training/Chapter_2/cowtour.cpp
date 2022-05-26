/*
ID: b.le611
PROG: cowtour
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
struct coord {
    int x;
    int y;
    coord(int a, int b) { x = a; y = b; }
    coord() { x = 0; y = 0; }
};

int n;
vt<coord> p; // pastures
vt<vt<double>> graph;
vt<vt<int>> comps;

double getDist(const coord& a, const coord& b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve() {
    vt<vt<double>> dist = graph;
    double best = INF;

    // floyd warshall

    FOR(k, n) 
        FOR(i, n) 
            FOR(j, n) 
                if ((dist[i][k] + dist[k][j] <= dist[i][j] || dist[i][j] == -1) && dist[i][k] >= 0 && dist[k][j] >= 0) 
                    dist[i][j] = dist[i][k] + dist[k][j];
    double f = -1;
    FOR(i, n)
        f = max(f, *max_element(all(dist[i])));
    FOR(i, n) {
        FOR(j, i+1, n) {
            if (dist[i][j] > 0) continue;

            double d1 = *max_element(all(dist[i]));
            double d2 = *max_element(all(dist[j]));

            best = min(best, max(f, d1+getDist(p[i], p[j])+d2));
        }
    }
    return best;
}

int main() {
    setIO("cowtour", 5);

    read(n);
    p.resize(n);
    graph.resize(n, vt<double>(n, -1));

    EACH(h, p)
        read(h.x, h.y);

    
    FOR(i, n) {
        string l;
        read(l);
        FOR(j, n)
            if (i == j) graph[i][j] = 0;
            else if (l[j] == '1') graph[i][j] = getDist(p[i], p[j]); 
    }

    double res = solve();
    print(res); // std::to_string rounds to 6 decimal places

    return 0;
}
