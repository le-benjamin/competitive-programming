#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (n > 1 && n&1) {
            cout << "-1\n";
            continue;
        } 
        for (int i = 1; i <= n; i+=2) {
            cout << i+1 << " " << i << " ";
        }
        cout << "\n";
    }

    return 0;
}