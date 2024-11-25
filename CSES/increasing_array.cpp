#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ll n; cin >> n;
    ll p; cin >> p;
    ll sum = 0;

    for (int i = 1; i < n; i++) {
        ll x; cin >> x;
        sum += max(0LL, p-x);
        p=max(p,x);
    }
    
    cout << sum << '\n';

    return 0;
}
