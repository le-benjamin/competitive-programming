#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char num[105];
        scanf("%s", num);

        int digitSum = 0;
        int evenNums = 0;
        bool hasZero = false;

        for (int i = 0; i < strlen(num); i++) {
            int a = num[i]-'0';
            digitSum += a;
            if (!(a&1)) evenNums++;
            if (a == 0) hasZero = true;
        }

        if (evenNums>1 && hasZero && digitSum%3==0 || digitSum==0)
            printf("red\n");
        else
            printf("cyan\n");
    }

    return 0;
}