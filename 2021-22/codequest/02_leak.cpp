#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        double v, f, l;
        scanf("%lf %lf %lf", &v, &f, &l);
        int vow = (int)floor(v/(f-l)*l + 0.5);
        printf("%d\n", vow);
    }
    return 0;
}