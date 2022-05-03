#include <bits/stdc++.h>
using namespace std;

int main() { 
    double totalDist = 0;
    int n;
    scanf("%d", &n);
    
    double x1, y1;
    scanf("%lf %lf", &x1, &y1);
    
    for (int i = 1; i < n; i++) {
        double x2, y2;
        scanf("%lf %lf", &x2, &y2);
        totalDist += sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        x1 = x2;
        y1 = y2;
    }
    
    printf("%.2f\n", totalDist);
    
    return 0;
}