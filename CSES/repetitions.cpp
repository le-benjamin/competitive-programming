#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int best = 1, c=0;
    char l = ' ';
    for (auto x : s) {
        if (x==l) {
            c++;
            best = max(best, c);
        } else {
            l = x;
            c = 1;
        }
    }
    cout << best << '\n';
    return 0;
}
