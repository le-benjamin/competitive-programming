/*
ID: b.le611
PROG: comehome
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
#define MAX_N 52 
const int barn = 'Z'-'A';
int p;
vt<vt<ll>> graph;
vt<bool> cows;

// helper function to convert character to node num
int getNum(char c) { return c <= 'Z' ? c-'A' : c-'a'+26; }

char getLet(int n) { return char(n < 26 ? 'A'+n : 'a'+n%26); }

int getMinInd(const vt<ll>& dist, const vt<bool>& visited) {
    int ind = -1;
    ll d = INF;
    FOR(i, MAX_N) 
        if (!visited[i] && dist[i] <= d) { ind = i; d = dist[i]; }
    return ind;
}

vt<ll> dijkstra(int start) {
    vt<ll> dist(MAX_N, INF);
    vt<bool> visited(MAX_N, false);

    dist[start] = 0;

    FOR(i, MAX_N) {
        start = getMinInd(dist, visited);
        visited[start] = true;
        FOR(j, MAX_N) 
            dist[j] = min(dist[j], dist[start]+graph[start][j]);
    }

    return dist;
}

int main() {
    setIO("comehome");

    read(p);

    cows.resize(MAX_N, true);
    graph.resize(MAX_N, vt<ll>(MAX_N, INF));
    FOR(i, MAX_N) graph[i][i] = 0;

    FOR(i, p) {
        string a, b;
        ll weight;
        read(a, b, weight);

        int x = getNum(a[0]), y = getNum(b[0]);

        if (isupper(a[0])) cows[x] = false;
        if (isupper(b[0])) cows[y] = false;

        graph[x][y] = graph[y][x] = min(graph[x][y], weight);
    }

    vt<ll> dist = dijkstra(barn);
    cows[barn] = true;

    int ind = getMinInd(dist, cows);

    print(getLet(ind), dist[ind]);


    return 0;
}
