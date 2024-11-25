#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long a = n*(n+1)/2;

    if (a&1) { cout << "NO\n"; return 0; }
    cout << "YES\n";

    return 0;
}