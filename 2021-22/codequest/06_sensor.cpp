#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int n;
        scanf("%d", &n);
        vector<bool> ids(n, 0);
        for (int i = 0; i < n-1; i++) {
            int ind;
            scanf("%d", &ind);
            ids[ind-1] = 1;
        }
        
        printf("%ld\n", find(ids.begin(), ids.end(), 0)-ids.begin()+1);
    }

    return 0;
}