/*
ID: b.le611
PROG: maze1
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
    //cin.tie(nullptr)->sync_with_stdio(0);
    //cout << fixed << setprecision(prec);
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
int w, h, n;
vt<vt<int>> graph;
vt<int> exits;
vt<int> dists;


void solve(int start) {
    vt<bool> visited(n, false);
    vt<int> q;
    int depth = 0;

    visited[start] = true;
    q.pb(start);

    while (!q.empty()) {
        depth++;
        vt<int> nq;

        EACH(x, q) 
            EACH(y, graph[x]) 
                if (!visited[y]) {
                    visited[y] = true;
                    dists[y] = min(dists[y], depth);
                    nq.pb(y);
                }

        q = nq;
    }
}

int main() {
    setIO("maze1");
    

    
    read(w, h);
    n = w*h;

    graph.resize(n); // adj list
    dists.resize(n, MOD);

    vt<string> maze(h*2+1);
{
    string l;
    getline(cin, l);
    FOR(i, h*2+1) {
        getline(cin, l);
        maze[i]=l;
        
    }
}


    FOR(i, 1, h*2+1, 2) {
        FOR(j, 1, w*2+1, 2) {
            if (i == 1 && maze[0][j] == ' ')
                exits.pb(i/2*w+j/2);
            if (j == 1 && maze[i][0] == ' ')
                exits.pb(i/2*w+j/2);
            if (j == w*2-1 && maze[i][w*2] == ' ')
                exits.pb(i/2*w+j/2);
            if (i == h*2-1 && maze[h*2][j] == ' ') 
                exits.pb(i/2*w+j/2);

            if (i < h*2-1 && maze[i+1][j] == ' ') {
                graph[i/2*w+j/2].pb((i/2+1)*w+j/2);
                graph[(i/2+1)*w+j/2].pb(i/2*w+j/2);
            }
            if (j < w*2-1 && maze[i][j+1] == ' ') {
                graph[i/2*w+j/2].pb(i/2*w+j/2+1);
                graph[i/2*w+j/2+1].pb(i/2*w+j/2);
            }
        }
    }

    EACH(x, exits) dists[x] = 0;
    EACH(x, exits) solve(x);
    print(*max_element(all(dists))+1);

    return 0;
}
