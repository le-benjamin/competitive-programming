/*
ID: b.le611
PROG: game1
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
int dp[105][105]; // include include
int sum[105][105];

int main() {
    setIO("game1");

    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &dp[i][i]);

        for (int a = 0; a <= i; a++) 
        for (int b = i; b < N; b++) {
            sum[a][b] += dp[i][i];
        }
    }

    for (int i = 1; i < N; i++) 
    for (int j = 0; j+i < N; j++) {
        dp[j][j+i] = sum[j][j+i]-min(dp[j][j+i-1], dp[j+1][j+i]);
    }

    printf("%d %d\n", dp[0][N-1], sum[0][N-1]-dp[0][N-1]);


    return 0;
}