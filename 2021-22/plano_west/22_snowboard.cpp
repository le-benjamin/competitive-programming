#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prices;
int n, l;

void solve() {
    for (int i = 0; i <= l; i++) 
        for (int p = 0; p <= l && p <= i; p++) 
            prices[i] = max(prices[i], prices[i-p]+prices[p]);
}

int main() {
    scanf("%d %d", &n, &l);
    prices.resize(l+1, 0);
    
    while (n--) {
        int len, pr;
        scanf("%d %d", &len, &pr);
        prices[len] = max(pr, prices[len]);
    }
    
    solve();
    
    printf("%d\n", prices[l]);
    
    return 0;
}