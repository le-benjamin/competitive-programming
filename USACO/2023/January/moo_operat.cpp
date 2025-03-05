#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vt vector
#define pb push_back

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        string s; cin >> s;

        if (s.find("MOO") != string::npos) {
            cout << s.length()-3;
        }
        else if (s.find("MOM") != string::npos) {
            cout << s.length()-2;
        }
        else if (s.find("OOO") != string::npos) {
            cout << s.length()-2;
        }
        else if (s.find("OOM") != string::npos) {
            cout << s.length()-1;
        }
        else {
            cout << -1;
        }
        
        cout << '\n';
    }
}