/*
ID: b.le611
PROG: shopping
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

struct Item {
    int c, k;
};

struct Offer {
    int n;
    Item item[5];
    int p;
};

map<int, int> id; // not exactly necessary given the constraints, but makes it easier to understand later on
Offer offer[110];
int dp[6][6][6][6][6];
int idIdx = 0;

int main() {
    setIO("shopping");

    memset(dp, MOD, sizeof(dp));
    dp[0][0][0][0][0] = 0;

    int s; cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> offer[i].n;
        for (int j = 0, c, k; j < offer[i].n; j++) {
            cin >> c >> k;
            if (!id.count(c)) id[c] = idIdx++;
            offer[i].item[id[c]].c = c;
            offer[i].item[id[c]].k = k;
        }
        cin >> offer[i].p;
    }

    // convert each regular price into an offer
    int bkt[5] = {0};
    int b; cin >> b;
    for (int i = s; i < s+b; i++) {
        offer[i].n = 1;
        int c; cin >> c;
        if (!id.count(c)) id[c] = idIdx++;
        cin >> bkt[id[c]] >> offer[i].p;
        offer[i].item[id[c]].c = c;
        offer[i].item[id[c]].k = 1;
    }

    // go through every offer
    for (int i = 0; i < s+b; i++) {
        int temp[5] = {0};
        for (int j = 0; j < 5; j++)
            temp[j] = offer[i].item[j].k;

        for (int a = temp[0]; a <= bkt[0]; a++) 
        for (int b = temp[1]; b <= bkt[1]; b++) 
        for (int c = temp[2]; c <= bkt[2]; c++) 
        for (int d = temp[3]; d <= bkt[3]; d++) 
        for (int e = temp[4]; e <= bkt[4]; e++) 
            dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a-temp[0]][b-temp[1]][c-temp[2]][d-temp[3]][e-temp[4]] + offer[i].p);
    }

    cout << dp[bkt[0]][bkt[1]][bkt[2]][bkt[3]][bkt[4]] << '\n';

    return 0;
}