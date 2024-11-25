#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int k = 1; k<=n; k++) {
        long long a=k*k,b=a*(a-1)/2;
        cout << b-(k>2?4*(k-1)*(k-2):0) << '\n';
    }
}