#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d\n", &n, &m);

        bool table[105][105];
        for (int i = 0; i < n; i++) {
            char c;
            for (int j = 0; j < m; j++) {
                scanf("%c", &c);
                table[i][j] = c-'0';
            }
            scanf("%c", &c);
        }

        bool valid = true;

        for (int r = 0; r < n-1; r++) {
            for (int c = 0; c < m-1; c++) {
                int count = 0;
                if (table[r][c]) count++;
                if (table[r+1][c]) count++;
                if (table[r][c+1]) count++;
                if (table[r+1][c+1]) count++;
                if (count == 3) {valid = false; break;}
            }
            if (!valid) break;
        }

        printf((valid ? "YES\n" : "NO\n"));
    }
    
    return 0;
}