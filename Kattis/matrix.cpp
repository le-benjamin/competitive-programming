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

int main() {
	using std::cout; using std::cin; using std::string;

	int a, b, c, d;
    int counter = 0;
    while (cin >> a >> b >> c >> d) {
        cout << "Case " << ++counter << ":" << std::endl;
        cout << d << " " << b*-1 << "\n";
        cout << c*-1 << " " << a << "\n";
    }


	return 0;
}
