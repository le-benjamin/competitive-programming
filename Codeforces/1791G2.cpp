#include <bits/stdc++.h>
using namespace std;

int a[200005];
int sum[200005]; // sum[i] = accumulate(a, a+i)
multiset<int> s;


void solve() {

    s.clear();

    int n, c; cin >> n >> c;

    for (int i = 1; i <= n; i++) { 
        cin >> a[i]; 
        s.insert(min(i+a[i], n+1-i+a[i])); 
    }

    // find best start
    int start = 1;
    for (int i = 2; i <= n; i++) 
        if (i+a[i] < start+a[start]) start = i;
    
    // std::multiset<int>::iterator iter;
    // for (iter = s.begin(); iter != s.end(); ++iter) cout << *iter + " ";

    int tp = 0;

    auto it = s.lower_bound(min(start+a[start], n+1-start+a[start]));
    c -= *it;
    s.erase(it);
    // cout << '\n' << start+a[start];
    
    while (c >= 0) {
        tp++;
        if (s.empty()) break;
        it = s.begin();
        c -= *it;
        // cout << ' ' << *it;
        s.erase(it);
    }


    // cout << '\n';
    cout << tp << '\n';
}

int main() {
    // freopen("data.out", "w", stdout);
    // freopen("data.in", "r", stdin);
    cin.tie(nullptr)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();

    return 0;
}