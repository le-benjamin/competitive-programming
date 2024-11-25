#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    ll s = 0;

    for (int i = 1; i < n; i++) {
        ll a; cin >> a;
        s+=a;
    }

    cout << n*(n+1)/2 - s;

    return 0;
}
