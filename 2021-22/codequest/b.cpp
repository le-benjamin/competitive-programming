#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d\n", &n);

    while (n--) {
        double speed, dist;
        scanf("%lf:%lf\n", &speed, &dist);

        if (speed >= dist) printf("SWERVE\n");
        else if (speed*5 >= dist) printf("BRAKE\n");
        else printf("SAFE\n");
    }

    return 0;
}