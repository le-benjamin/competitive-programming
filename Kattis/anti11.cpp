// incomplete, integer overflow?? idk

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

ll fibbonaci[10001] = {1, 1};


ll gen(int n) {
	if (n > 1) {
		ll a;
		if (fibbonaci[n-1] != 0 && fibbonaci[n-2] != 0) a = fibbonaci[n-1]+fibbonaci[n-2];
		else a = gen(n-1) + gen(n-2);
		fibbonaci[n] = a;
		return a;
	}
	else return 1;

}


int main() {
	using std::cout; using std::cin; using std::string;

	int t;
	cin >> t;

	while(t--) {
		ll n;
		cin >> n;
		cout << gen(n+1) << std::endl;
	}

	return 0;
}
