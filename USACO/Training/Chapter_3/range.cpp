/*
ID: b.le611
PROG: range
LANG: C++14
*/

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

void setIO(string name = "", int prec = 2) { // lim prec = 15
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << fixed << setprecision(prec); // use cout instead of print() or write()
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout); 
    }
}

int N;
int dp[255][255]; // dp[i][j] = max square size with bottom right corner at (i, j)
int freq[255] = {0};

int main() {
    setIO("range");

    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++) 
    for (int j = 1; j <= N; j++) {
        char c; cin >> c;
        if (c == '1') {
            dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
            for (int k = 2; k <= dp[i][j]; k++) freq[k]++;
        }
    }
    
    for (int i = 2; i <= N; i++) 
        if (freq[i]) cout << i << " " << freq[i] << "\n";
    
    return 0;
}