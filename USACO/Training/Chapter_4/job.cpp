/*
ID: b.le611
PROG: job
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

int N, M1, M2;
vt<int> A, B;

void solve() {
    vt<int> done(N, 0);
    vt<int> time;
    int cnt, cur;

    time.assign(M1, 0);
    cnt = N, cur = 0;
    for (; cnt > 0; cur++) {
        for (int i = 0; i < M1 && cnt > 0; time[i]++, i++) {
            if (time[i] >= A[i]) {
                time[i] = 0;
                done[N-cnt] = cur;
                cnt--;
            }
        }
    }
    cout << cur-1 << " ";

    time.assign(M2, 0);
    cnt = N, cur = 0;
    for (; cnt > 0; cur++) {
        for (int i = 0; i < M2 && cnt > 0; time[i]++, i++) {
            if (time[i] >= B[i]) {
                done[cnt-1] += cur;
                time[i] = 0;
                cnt--;
            }
        }
    }

    cout << *max_element(all(done)) << '\n';
}

int main() {
    setIO("job");

    cin >> N >> M1 >> M2;

    A.assign(M1, 0);
    B.assign(M2, 0);
    for (int& a : A) cin >> a;
    for (int& b : B) cin >> b;

    solve();

    return 0;
}
