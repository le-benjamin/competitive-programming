/*
ID: Ben Le [b.le611]
PROG: namenum
LANG: C++
*/

#include <stdio.h>
#include <string.h>
#include <map>

#define vt std::vector
#define pb push_back
#define ll long long
using namespace std;

map<char, char> ID;

void genMap() {
	ID['A'] = '2'; ID['B'] = '2'; ID['C'] = '2';
	ID['D'] = '3'; ID['E'] = '3'; ID['F'] = '3';
	ID['G'] = '4'; ID['H'] = '4'; ID['I'] = '4';
	ID['J'] = '5'; ID['K'] = '5'; ID['L'] = '5';
	ID['M'] = '6'; ID['N'] = '6'; ID['O'] = '6';
	ID['P'] = '7'; ID['R'] = '7'; ID['S'] = '7';
	ID['T'] = '8'; ID['U'] = '8'; ID['V'] = '8';
	ID['W'] = '9'; ID['X'] = '9'; ID['Y'] = '9';
	ID['Q'] = '.'; ID['Z'] = '.';
}


int main() {
	
	genMap();

	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	char brand[15];
	char name[15];
	
	scanf("%s", brand);

	freopen("dict.txt", "r", stdin);

	bool valid = false;
	while (scanf("%s", name) != EOF) {
		char num[15];
		for (int i = 0; i < sizeof(name)/sizeof(name[0]); i++) {
			num[i] = ID[name[i]];
		}
		num[strlen(name)] = '\0';
		if (strcmp(num, brand) == 0) {
			printf("%s\n", name);
			valid = true;
		}
	}

	if (!valid) printf("NONE\n");

	return 0;
}
