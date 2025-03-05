#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vt vector
#define pb push_back

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    // freopen("data.in", "r", stdin);

    int n;
    string s;
    vt<int> e;

    int g1 = -1, g2 = -1, h1 = -1, h2 = -1;

    cin >> n >> s;
    e.assign(n, 0);
    for (auto& x : e) { cin >> x; x--; }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'G' && g1 < 0) g1 = i;
        if (s[i] == 'H' && h1 < 0) h1 = i;
        if (g1 >= 0 && h1 >= 0) break;
    }

    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'G' && g2 < 0) g2 = i;
        if (s[i] == 'H' && h2 < 0) h2 = i;
        if (g2 >= 0 && h2 >= 0) break;
    }


    int p = 0;

    if (e[g1] >= g2) {
        for (int i = 0; i < g1; i++) 
            if (s[i]=='H' && e[i]>=g1 && i != h1) p++;
    }
    
    if (e[h1] >= h2) {
        for (int i = 0; i < h1; i++) 
            if (s[i]=='G' && e[i]>=h1 && i != g1) p++;
        
    }

    if ((e[g1] >= g2 || (e[g1] >= h1 && g1 < h1)) && (e[h1] >= h2 || (e[h1] >= g1 && h1 < g1))) p++;
    
    cout << p << '\n';

}