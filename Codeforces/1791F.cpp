#include <bits/stdc++.h>
using namespace std;

int sum_digits(int n) {
    int sum = 0;

    for (; n > 0; n/=10) sum += n%10;

    return sum;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<int> s; // set of indices of numbers > 9

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 9) s.insert(i);
    }

    while (q--) {
        int o; cin >> o;
        if (o == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            int cur = l;

            while (!s.empty()) {
                auto it = s.lower_bound(cur);
                if (it == s.end() || *it > r) break; // check if you need to keep searching
                int i = *it;
                a[i] = sum_digits(a[i]);
                if (a[i] <= 9) s.erase(it);
                cur = i+1;
            }

        } else if (o == 2) {
            int x; cin >> x;
            cout << a[x-1] << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();

    return 0;
}