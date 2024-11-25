#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    if (n==1) { cout << "1\n"; return 0; }
    if (n<=3) { cout << "NO SOLUTION\n"; return 0; }

    cout << n-1;
    for (int i = (n&1?2:1); i<n-1; i+=2)
        cout << ' ' << i;
    cout << ' ' << n;
    for (int i = n-2; i>=1; i-=2) 
        cout << ' ' << i;

    return 0;
}
