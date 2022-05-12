/*
ID: b.le611
PROG: pprime
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
    bool flag=1;
    string res;
    EACH(x, v) {
		if(!flag) res+=' ';
		flag=0;
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
int a, b;
vt<int> primes;

void sieve(int n) {
    vt<bool> p(10001, true); // sqrt(100,000,000) = 10,000
    for (int i = 2; i <= 10001; i++) {
        if (!p[i]) continue;
        primes.pb(i);
        for (int j = i*i; j <= 10001; j+=i)
            p[j] = false;
    }
}

bool isPrime(int n) {
    EACH(num, primes) {
        if (num >= n) break;
        if (n%num == 0) return false;
    }
    return true;
}

int main() {

    setIO("pprime");
    read(a, b);
    sieve(b);

    // gen palindromes, less pals than primes probably, idk
    // 1 digit
    FOR(d1, 2, 10) {
        if (d1 > b) return 0;
        if (d1 >= a && isPrime(d1)) print(d1);
    }

    // 2 digit
    FOR(d1, 1, 10, 2) {
        int num = d1*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }

    // 3
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) {
        int num = d1*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }
    
    // 4
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) {
        int num = d1*1000+d2*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }

    // 5
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) 
    FOR(d3, 10) {
        int num = d1*10000+d2*1000+d3*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }

    // 6
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) 
    FOR(d3, 10) {
        int num = d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }

    // 7
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) 
    FOR(d3, 10) 
    FOR(d4, 10) {
        int num = d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);

    }

    // 8
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) 
    FOR(d3, 10) 
    FOR(d4, 10) {
        int num = d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }
    
    // 9
    FOR(d1, 1, 10, 2) 
    FOR(d2, 10) 
    FOR(d3, 10) 
    FOR(d4, 10) 
    FOR(d5, 10) {
        int num = d1*100000000+d2*10000000+d3*1000000+d4*100000+d5*10000+d4*1000+d3*100+d2*10+d1;
        if (num > b) return 0;
        if (num >= a && isPrime(num)) print(num);
    }

    return 0;
}
