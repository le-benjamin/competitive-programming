#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while(t--){
        ll y, x; cin >> y >> x;
        if (y>=x) cout << (y-1)*(y-1)+(y&1?x:2*y-x) << '\n';
        else cout << (x-1)*(x-1)+(x&1?2*x-y:y) << '\n';
    }
    return 0;
}
