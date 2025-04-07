#include <bits/stdc++.h>
using namespace std;

int solve() {
    int r = 0; 

    int n; cin >> n;
    int bf, bi; cin >> bf >> bi;

    vector<int> v;
    int tempInd = 0;
    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        int ci, ri; cin >> ci >> ri;
        if (!m.count(ci)) m[ci] = {0, 0};
        if (ri > m[ci].second) {
            m[ci].first = tempInd++;
            m[ci].second = ri;
            v.push_back(ri);
        }
    }

    


    return r;
}

int main() {
    freopen("slotmachine.in", "r", stdin);
    freopen("slotmachine.out", "w", stdout);
    int tc; cin >> tc;

    for (int i = 1; i <= tc; i++) 
        cout << "Case #" << i << ": " << solve() << '\n';

    return 0;
}