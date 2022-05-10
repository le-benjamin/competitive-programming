/*
ID: Ben Le [b.le611]
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
	using std::ofstream; using std::ifstream;

	ifstream in ("ride.in");
	ofstream out ("ride.out");

	char a[8], b[8];

	in >> a >> b;

	int aVal = 1, bVal = 1;

	for (int i = 0; a[i] != '\0'; i++) aVal *= a[i]-64;
	for (int i = 0; b[i] != '\0'; i++) bVal *= b[i]-64;

	out << ( (aVal%47 == bVal%47) ? "GO" : "STAY" ) << '\n';
	return 0;
}
