/*
ID: b.le611
PROG: combo
LANG: C++
*/

#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

int ja, jb, jc, ma, mb, mc;

int n;


bool valid(int a, int b, int c) {
	if ((abs(ja-a) > 2 ? abs(min(ja, a)+n-max(ja, a)) : abs(ja-a)) <= 2 && 
		(abs(jb-b) > 2 ? abs(min(jb, b)+n-max(jb, b)) : abs(jb-b)) <= 2 &&
		(abs(jc-c) > 2 ? abs(min(jc, c)+n-max(jc, c)) : abs(jc-c)) <= 2 || 
		(abs(ma-a) > 2 ? abs(min(ma, a)+n-max(ma, a)) : abs(ma-a)) <= 2 && 
		(abs(mb-b) > 2 ? abs(min(mb, b)+n-max(mb, b)) : abs(mb-b)) <= 2 &&
		(abs(mc-c) > 2 ? abs(min(mc, c)+n-max(mc, c)) : abs(mc-c)) <= 2) return true;

	return false;
}


int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

    scanf("%d", &n);
	
	scanf("%d %d %d", &ja, &jb, &jc);
	scanf("%d %d %d", &ma, &mb, &mc);

	int total = 0;

	// 1M operations, 100^3 max
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++) 
				if (valid(i, j, k)) total++;

	printf("%d\n", total);

	return 0;
}
