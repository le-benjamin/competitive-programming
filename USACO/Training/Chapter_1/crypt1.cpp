/*
ID: b.le611
PROG: crypt1
LANG: C++
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;


vector<int> digits;
bool exists[10];

bool validNum(int num, int len) {
    if (len != -1 && num%(int)pow(10, len) != num) {
        return false;
    }
    while (num > 0) {
        if (!exists[num%10]) return false;
        num /= 10;
    }
    return true;
}

int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        digits.push_back(t);
        exists[t] = true;
    }

    int total = 0;

    for (int a : digits) {
        for (int b : digits) {
            for (int c : digits) {
                int f1 = a*100 + b*10 + c;
                for (int d : digits) {
                    for (int e : digits) {
                        
                        int f2 = d*10 + e;
                        
                        if (validNum(f1*e, 3) && validNum(f1*d, 3) && validNum(f1*f2, -1)) total++;
                    }
                }
            }
        }
    }

    printf("%d\n", total);

	return 0;
}
