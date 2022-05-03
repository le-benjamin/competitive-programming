/*
ID: b.le611
TASK: dualpal
LANG: C++                 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void numToBase(char res[], int num, int base) {
    int index = 0;

    while (num > 0) {
        res[index++] = (char)(num%base >= 10 ? num%base+'A'-10: num%base+'0');
        num /= base;
    }
    res[index] = '\0';
    reverse(res, res+index);
}

bool isPalin(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1])
            return false;
    }
    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n, s;
    scanf("%d %d", &n, &s);

    for (s++; n > 0; s++) {
        int palCount = 0;
        
        for (int i = 2; i <= 10; i++) {
            char converted[300];
            numToBase(converted, s, i);
            if (isPalin(converted)) palCount++;
        }

        if (palCount >= 2) {
            printf("%d\n", s);
            n--;
        }
    }

    return 0;
}