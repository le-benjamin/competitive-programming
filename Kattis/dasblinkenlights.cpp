#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define vt std::vector
#define pb push_back
#define ll long long
#define PI 3.1415926535897932

int gcd(int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main() {
	using std::cout; using std::cin; using std::string;

	int a, b, c;
	cin >> a >> b >> c;

	if (std::min(a, b) * (std::max(a,b)/gcd(std::max(a, b), std::min(a,b))) <= c)
		cout << "yes";	
	else cout << "no";

	return 0;
}
