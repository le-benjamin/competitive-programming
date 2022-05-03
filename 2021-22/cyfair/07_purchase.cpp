#include <stdio.h>
#include <math.h>
using namespace std;


int main() {
    double dd;
    scanf("$%lf", &dd);
    dd *= 108.25;
    long long d = floor(dd+.5);
    
    double vals[8] = {2000, 1000, 500, 100, 25, 10, 5, 1};
    char words[8][20] = {"20 dollar bills", "10 dollar bills", "5 dollar bills", "1 dollar bills", "quarters", "dimes", "nickels", "pennies"};
    
    for (int i = 0; i < 8; i++) {
        int amt = d/vals[i];
        d -= amt*vals[i];
        if (amt > 0) {
            printf("%d %s", amt, words[i]);
            if (d > 0) printf(", ");
        }
    }

    
    return 0;
}