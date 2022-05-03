/*
ID: b.le611
TASK: palsquare
LANG: C++                 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long


void conver(char res[], int num, int base) {
    int index = 0;

    while (num > 0) {
        res[index++] = (char)(num%base >= 10 ? num%base+'A'-10: num%base+'0');
        num /= base;
    }
    
    res[index] = '\0';
    reverse(res, res+index);
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b;
    scanf("%d", &b);

    for (int i = 1; i <= 300; i++) {
        char n[100], r1[100], r2[100];
        conver(n, i, b);
        conver(r1, i*i, b);
        conver(r2, i*i, b);
        reverse(r2, r2+strlen(r2));
        if (strcmp(r1, r2)==0) {
            printf("%s %s\n", n, r1);
        }
    }
}