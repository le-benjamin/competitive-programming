#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

int main() {
	using std::cout; using std::cin; using std::string;

	int n;
	cin >> n;

	ll sum = 0;
	
	while(n--) {
		ll p;
		cin >> p;
		sum += pow(p/10, p%10);
	}

	cout << sum;

	return 0;
}
