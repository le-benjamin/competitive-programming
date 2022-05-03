#include <iostream>
#include <cmath>
#include <string>

int main() {
	
	for (int i = 0; i < 2; i++) {
		std::string team;
		double a, n, t;
		std::cin >> team >> a >> n >> t;
		std::cout << team << " " << (int)round(((n+1)*t)/(a/10)) << "%\n";
	}

	return 0;
}
