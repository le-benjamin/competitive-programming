// ACC
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

    int t;
    scanf("%d", &t);
    
    while(t--) {
        ll p, r, f;
        scanf("%lld %lld %lld", &p, &r, &f);
        int counter = 0;

        while (p <= f) {
            counter++;
            p *= r;
        }
        printf("%d\n", counter);
    }
	return 0;
}
