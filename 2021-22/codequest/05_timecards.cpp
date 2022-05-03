#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d\n", &n);

    while (n--) {
        char *name = (char*)malloc(sizeof(char)*250);
        int totalTime = 0, h, m;
        scanf("%[^,]", name);

        for (int i = 0; i < 4; i++) {
            scanf(",%d:%d", &h, &m);
            totalTime += h*60 + m;
        }
        scanf(",%d:%d\n", &h, &m);
        totalTime += h*60 + m;

        h = totalTime/60;
        m = totalTime%60;
        
        printf("%s=", name);

        if (h != 0) {
            if (h == 1) printf("1 hour");
            else printf("%d hours", h);
            if (m != 0) printf(" ");
        }
        if (m != 0) {
            if (m == 1) printf("1 minute");
            else printf("%d minutes", m);
        }
        printf("\n");
    }
    return 0;
}