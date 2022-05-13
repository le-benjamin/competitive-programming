/*
ID: b.le611
PROG: castle
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
#define MAX_MN 51
#define MAX_NODES 2501
int M, N;
int NODES;
int maxSZ = -1;
vt<int> compSZ;
vt<int> comp;
vt<vt<int>> adj;

void floodFill() {
    int compNum = 0;
    FOR(i, NODES) {
        if (comp[i] == -1) {
            compSZ.pb(0);
            comp[i] = -2;

            while (1) {
                int visited = 0;
                FOR(j, NODES) {
                    if (comp[j] == -2) {
                        visited++;
                        comp[j] = compNum;
                        compSZ[compNum]++;
                        EACH(k, adj[j]) {
                            if (comp[k] == -1) 
                                comp[k] = -2;
                        }
                    }
                }
                if (!visited) break;
            }
            maxSZ = max(maxSZ, compSZ[compNum]);
            compNum++;
        }
    }
}

void solve() {

}

int main() {
    setIO("castle");

    read(M, N);
    NODES = M*N;
    adj.resize(NODES);
    comp.resize(NODES, -1);

    // gen adj list
    FOR(i, N) {
        FOR(j, M) {
            int ind = i*M+j;
            int x;
            read(x);
            if (x-8 < 0) 
                adj[ind].pb(ind+M);
            else x-=8;

            if (x-4 < 0)
                adj[ind].pb(ind+1);
            else x-=4;

            if (x-2 < 0) 
                adj[ind].pb(ind-M);
            else x-=2;

            if (x-1 < 0) 
                adj[ind].pb(ind-1);
            else x-=1;

            sort(all(adj[ind]));
        }
    }

    floodFill();
    print(sz(compSZ)); // 1st line of output
    print(maxSZ); // 2nd 

    int rm = 0;
    int dir = 2;
    int total = -1;

    FOR(c, M) {
        FOR(r, N-1, -1, -1) {
            int ind = r*M+c;
            if (r > 0) {
                if (comp[ind] != comp[ind-M]) {
                    int sum = compSZ[comp[ind]]+compSZ[comp[ind-M]];
                    if (sum > total) {
                        total = sum;
                        rm = ind;
                        dir = 2;
                    }
                }
            }
            if (c < M-1) {
                if (comp[ind] != comp[ind+1]) {
                    int sum = compSZ[comp[ind]]+compSZ[comp[ind+1]];
                    if (sum > total) {
                        total = sum;
                        rm = ind;
                        dir = 4;
                    }
                }
            }
        }
    }

    print(total); // 3rd
    print(rm/M+1, rm%M+1, (dir == 2 ? 'N' : 'E')); // 4



    return 0;
}
