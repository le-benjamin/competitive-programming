#include <stdio.h>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int coins[55];
int dp[50005][55];
bool checked[50005];
int n, m, lastGen = 1;


void gen(int mp) {
    if (mp < 0 || checked[mp]) return;
    
    for (int p = lastGen; p <= mp; p++) {
        if (checked[p]) continue;
        
        for (int c = 0; c < m; c++) {
            if (coins[c] > p || dp[p][c] > 0) continue;
            int t = 0;
            for (int v = 0; v <= c; v++) {
                t += dp[p-coins[c]][v];
                t %= MOD;   
            }
            
            dp[p][c] = t;
        }
        checked[p] = true;
    }
    lastGen = mp;
}


int main() {
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d", &coins[i]);
    sort(coins, coins+m);
    for (int i = 0; i < m; i++)
        dp[coins[i]][i] = 1;

    checked[0] = true;
    
    while (n--) {
        int p;
        scanf("%d", &p);
        
        gen(p);
        
        int t = 0;
        for (int i = 0; i < m; i++) {
            t += dp[p][i];
            t %= MOD; 
        }
        printf("%d\n", t);
    }
    
    return 0;
}
