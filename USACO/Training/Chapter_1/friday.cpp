/*
ID: Ben Le [b.le611]
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define vt std::vector
#define pb push_back
#define ll long long

int main() {
	using std::ofstream; using std::ifstream; using std::string;

	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	
	int n;
	fin >> n;

	int count[7] = {0};

	int offset = 0;

	for (int year = 1900; year < 1900+n; year++) {
		int date = offset+1;
		date += 12;

		count[date%7]++;

		for (int month = 1; month < 12; month++) {
			if (month != 2 && month != 9 && month != 4 && month != 6 && month != 11) {
				date += 31;
			} else if (month == 2) {
				if (year%4 == 0) {
					if (year%100 == 0) {
						if (year%400 == 0) {
							date += 29;
						} else date += 28;
					} else date += 29;
				} else date += 28;
			} else date += 30;
			count[date%7]++;
		}
		date += 31-13;
		offset = date%7;
	}

	fout << count[6] << " ";
	for (int i = 0; i < 6; i++) fout << count[i] << ((i<5)?" ":"\n");

	return 0;
}
