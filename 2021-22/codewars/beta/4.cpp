#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string arr[] = {"Initial", "Speculated", "Current"};
	
	double cur = 0, init = 0;
	for (int i = 0; i < 3; i++) {
		double a, b;
		cin >> a >> b;
		if (i == 0) init = a*b;
		if (i == 2) cur = a*b;
		//cout << arr[i] << ": " << (round(a*b*100)/10.0) << '\n';
		printf("%s: %.2f\n", arr[i].c_str(), a*b);
	}
	printf("Net: %.2f", cur-init);
	return 0;
}
