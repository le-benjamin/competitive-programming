#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    unsigned ll q;
    scanf("%llu", &q);
    
    while (q--) {
        unsigned ll n;
        scanf("%llu", &n);

        int moves = 0;
        while (n > 1) {
            if (n%2 == 0)
                n /= 2;
            else if (n%3 == 0)
                n = (n*2)/3;
            else if (n%5 == 0) 
                n = (4*n)/5;
            else {
                moves = -1;
                break;
            }
            moves++;
        }
        printf("%d\n", moves);
    }

    return 0;
}