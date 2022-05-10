/*
ID: Ben Le [b.le611]
PROG: milk2
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

struct interval {
	int start;
	int end;
};

bool compareStart (const interval &a, const interval &b) {
	return a.start < b.start;
}

int main() {
	using std::ofstream; using std::ifstream; using std::string;

	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	
	int n;
	fin >> n;
	
	vt<interval> intervals;
	vt<interval> timeTable;
	while (n--) {
		int start, end;
		fin >> start >> end;
		intervals.pb({start, end});
		
		// check if interval is within another interval
		bool withinTable = false;
		std::sort(timeTable.begin(), timeTable.end(), compareStart);
		for (int i = 0; i < timeTable.size(); i++) {
			if (timeTable[i].start < start && start < timeTable[i].end) {
				if (end > timeTable[i].end) { 
					timeTable[i].end = end; 
				}
				withinTable = true;
				break;
			}
			if (start < timeTable[i].start) {
				if (end > timeTable[i].start) {
					timeTable[i].start = start;
					withinTable = true;
					if (end > timeTable[i].end) timeTable[i].end = end;
					break;
				}
			}
		}

		if (!withinTable) timeTable.pb({start, end});
	}

	// merge any overlapping intervals
	std::sort(timeTable.begin(), timeTable.end(), compareStart);
	for (int i = timeTable.size()-1; i > 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			if (timeTable[i].start <= timeTable[j].end) {
				if (timeTable[i].end > timeTable[j].end) {
					timeTable[j].end = timeTable[i].end;
				}
				timeTable.erase(timeTable.begin() + i);
				break;
			}
		}
	}	
	
	int milking = 0, noMilking = 0;
	for (int i = 0; i < timeTable.size(); i++) {
		milking = std::max(milking, timeTable[i].end - timeTable[i].start);
		if (i < timeTable.size()-1) noMilking = std::max(noMilking, timeTable[i+1].start - timeTable[i].end);
	}

	fout << milking << " " << noMilking << "\n";

	// for (auto x : timeTable) std::cout << "start : " << x.start << "	end : " << x.end << "\n";

	return 0;
}
