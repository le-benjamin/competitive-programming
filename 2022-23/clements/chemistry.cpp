#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin >> n;
    
    bool f = false;
    
    while (n--) {
        if (f) cout << "\n";
        int q; cin >> q;
        vector<string> v(q, "");
        for (auto& a : v) cin >> a;
        
        sort(v.begin(), v.end());
        int place = 1;
        do {
            cout << place << ". ";
            for (int i = 0; i < q; i++) cout << v[i] << " ";
            cout << '\n';
            place++;
        } while (next_permutation(v.begin(), v.end()));
        
        f = true;
    }
    
    return 0;
}
