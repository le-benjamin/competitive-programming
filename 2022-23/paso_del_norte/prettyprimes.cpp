#include <bits/stdc++.h>

using namespace std;
int main() {
    
    vector<bool> s(10005, true);
    for (int i = 2; i < int(s.size()); i++) {
        if (s[i])
            for (int j = i*i; j < int(s.size()); j+=i) s[j] = false;
    }
    
    int n; cin >> n;
    
    while (n--) {
        int x; cin >> x;
        int sum = 0;
        
        for (int i = 2; i < x; i++) 
            if(s[i]) sum += i;
        
        cout << sum << '\n';
    }
    
    
    return 0;
}