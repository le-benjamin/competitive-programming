#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int cnt = 1;
        string pres; cin >> pres;
        for (int i = 1; i < n; i++) {
            string temp; cin >> temp;
            if (pres == temp) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}