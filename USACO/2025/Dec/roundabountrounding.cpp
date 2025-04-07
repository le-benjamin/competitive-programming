#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9+7;
const ll INF = 1e18;

void setIO(string name = "", int prec = 2) { 
    // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
}

double get_p(int n) {
    return ceil(log10(n));
}

int chainRound(int n) {
    int p = get_p(n);
    for (int i = 1; i <= p; i++) {
        double ex = pow(10, i);
        n = round(n/ex)*ex;
    }
    return n;
}

int normalRound(int n) {
    int p = get_p(n);
    double ex = pow(10, p);
    return round(n/ex)*ex;
}


void solve() {

}

int main() {
    setIO();

    map<int, int> m;

    // cout << normalRound(48);

    // for (int i = 2; i <= 1e5; i++) {
    //     m[i] = m[i-1] + (chainRound(i) != normalRound(i));
    // }

    for (int i = 1; i <= 6; i++) {
        int a = 5;
        for (int j = 1; j <= i; j++) {
            a += 4*pow(10, j);
        }

        if (i > 1) m[a] =  m[5*(int)pow(10,i-1)-1]+1;
        else m[a] = 1;
        int b = 5*pow(10, i);
        for (int j = a+1; j < b; j++) {
            m[j] = m[j-1]+1;
        }

        // for (int j = 5*pow(10, i); j < a + 4*pow(10, i+1) - 1; j++) {
        //     m[j] = m[j-1];
        // }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << m.upper_bound(N)->second - 1 << '\n';
    }

    /**
     * every 4*10^n + 4*10^n-1 + ... + 4*10^1 + 5 until 5*10^n - 1
     * 49999	|	6170
     * 50000	|	6170
     */

    // for (int i = 1; i < 1e5; i++) {
    //     cout << i << "\t|\t" << m[i] << '\n';
    // }

    return 0;
}