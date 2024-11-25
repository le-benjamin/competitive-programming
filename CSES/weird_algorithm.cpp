#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    long long n; cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n&1) n=n*3+1;
        else n>>=1;
    }
    cout << n;
}