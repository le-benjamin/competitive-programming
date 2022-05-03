#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int* candies = new int[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &candies[i]);

        sort(candies, candies+n);

        if (n == 1) {
            if (candies[0] > 1) printf("NO\n");
            else printf("YES\n");
            continue;
        }

        if (abs(candies[n-1] - candies[n-2]) > 1)
            printf("NO\n");
        else
            printf("YES\n");

        delete[] candies;

    }

    return 0;
}