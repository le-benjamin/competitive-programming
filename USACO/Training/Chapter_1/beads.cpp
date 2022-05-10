/*
ID: Ben Le [b.le611]
PROG: beads
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

	ofstream fout ("beads.out");
	ifstream fin ("beads.in");

	int n;
	string necklace;
	fin >> n >> necklace;

	// find substrings at ends and append to opposite ends; should be a copy of the first longest strong
	
	string first = "", last = "";

	// find "type" of first segment
	
	char type = necklace[0];
	for (int i = 0; type == 'w' || i < n; i++) { type = necklace[i]; 
	//	if (i == n-1) {fout << n << "\n"; return 0;}
	}
	for (int i = 0; (necklace[i] == type || necklace[i] == 'w') && i < n; i++) first += necklace[i];

	if (first.length() == n) {fout << n << "\n"; return 0;}

	type = necklace[n-1];
	for (int i = n-1; type == 'w' || i >= 0; i--) type = necklace[i];
	for (int i = n-1; necklace[i] == type || necklace[i] =='w'; i--) last = necklace[i] + last; // create string in reverse

	necklace = last + necklace; necklace += first;

	int longest = 0, index = 1;
	
	type = necklace[0];
	for (int i = 0; type == 'w' && i < n; i++) type = necklace[i];
	while (necklace[index] == type || necklace[index] == 'w') index++;
	
	
	while (1) {
		int lenPrev = 0, lenNext = 0;
		// find len of prev word

		type = necklace[index-1];
		for (int i = index-1; type == 'w' && i >= 0; i--) type = necklace[i];
		for (int i = index-1; necklace[i] == type || necklace[i] =='w'; i--) lenPrev++;

		type = necklace[index];
		for (int i = index; type == 'w' && i < n; i++) type = necklace[i];
		for (int i = index; necklace[i] == type || necklace[i] == 'w'; i++) lenNext++;
		longest = std::max(longest, lenPrev+lenNext);
		
		index += lenNext;
		if (index >= necklace.length()) break;
	}
	fout << longest << "\n";
	return 0;
}
