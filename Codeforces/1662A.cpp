#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    
    int t;
    cin >> t;

    while (t--) {
        int n, b, d, mb[10] = {0}; // mb = max beauty, mb[i] = beauty, i = diff

        cin >> n;

        while(n--) {
            cin >> b >> d;
            mb[d-1] = max(mb[d-1], b);
        }

        if (find(mb, mb+10, 0) == mb+10) 
            cout << accumulate(mb, mb+10, 0) << '\n';
        else 
            cout << "MOREPROBLEMS\n";
    }

    return 0;
}