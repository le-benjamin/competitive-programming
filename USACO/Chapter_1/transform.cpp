/*
ID: Ben Le [b.le611]
PROG: transform
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

// 90 degree cw
bool one(vt<vt<char>> shape1, vt<vt<char>> shape2, int d) {
	for (int r = 0; r <= d; r++) {
		for (int c = 0; c <= d; c++) {
			if (shape1[r][c] != shape2[c][d-r]) return false;
		}
	}
	return true;
}


// 180 degree
bool two(vt<vt<char>> shape1, vt<vt<char>> shape2, int d) {
	for (int r = 0; r <= d; r++) {
		for (int c = 0; c <= d; c++) {
			if (shape1[r][c] != shape2[d-r][d-c]) return false;
		}
	}
	return true;
}

// 270 degree cw
bool three(vt<vt<char>> shape1, vt<vt<char>> shape2, int d) {
	for (int r = 0; r <= d; r++) {
		for (int c = 0; c <= d; c++) {
			if (shape1[r][c] != shape2[d-c][r]) return false;
		}
	}
	return true;
}

// no change
bool six(vt<vt<char>> shape1, vt<vt<char>> shape2, int d) {
	for (int r = 0; r <= d; r++) {
		for (int c = 0; c <= d; c++) {
			if (shape1[r][c] != shape2[r][c]) return false;
		}
	}
	return true;
}


// reflection
vt<vt<char>> reflect(vt<vt<char>> shape, int d) {
	vt<vt<char>> nShape (d+1, vt<char>(d+1)); 
	for (int r = 0; r <= d; r++) {
		for (int c = 0; c <= d; c++) {
			nShape[r][c] = shape[r][d-c];
		}
	}
	return nShape;
}


int main() {
	using std::ofstream; using std::ifstream; using std::string;

	ofstream fout ("transform.out");
	ifstream fin ("transform.in");

	int d;
	fin >> d;

	vt<vt<char>> shape1 (d, vt<char>(d));
	vt<vt<char>> shape2 (d, vt<char>(d));

	for (int row = 0; row < d; row++) { 
		for (int col = 0; col < d; col++) {
			char c;
			fin >> c;
			shape1[row][col] = c;
		}
	}
	
	for (int row = 0; row < d; row++) { 
		for (int col = 0; col < d; col++) {
			char c;
			fin >> c;
			shape2[row][col] = c;
		}
	}

	d--; //needed to pass to checker functions
	
	int out;

	if (one(shape1, shape2, d)) out = 1; 
	else if (two(shape1, shape2, d)) out = 2;
	else if (three(shape1, shape2, d)) out = 3;
	else if (six(shape1, shape2, d)) out = 6;
	else {
		shape1 = reflect(shape1, d);

		if (six(shape1, shape2, d)) out = 4;
		else if (one(shape1, shape2, d)) out = 5; 
		else if (two(shape1, shape2, d)) out = 5;
		else if (three(shape1, shape2, d)) out = 5;
		else out = 7;
	}	

	fout << out << "\n";
	

	return 0;
}
