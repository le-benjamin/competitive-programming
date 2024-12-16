#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "codeforces";
    int t; cin >> t;

    while (t--) {
        string c; cin >> c;
        cout << (s.find(c) != string::npos ? "YES\n" : "NO\n");
    }

    return 0;
}