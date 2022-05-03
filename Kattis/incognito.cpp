// TLE

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

ll total = 0;

template <typename iter>
int calc(int prevProd, iter begin, iter end, std::map<std::string, int> memo = {}) {
    for (iter it = begin; it != end; it++) {
        std::cout << *it << " ";
        total += prevProd * *it;
        if (begin+1 != end) calc(*it, it+1, end);
    }

    std::cout << std::endl;
    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    if (!n) {std::cout << 0 << std::endl; return;}
    total = 0;
    
    std::map<std::string, int> attributes;

    for (int i = 0; i < n; i++) {
        std::string name, attribute;
        std::cin >> name >> attribute;

        if (attributes.count(attribute)) attributes[attribute]++;
        else attributes[attribute] = 1;
    }

    vt<int> nums;
    for (auto x : attributes) {
        nums.pb(x.second);
    }

    calc(1, nums.begin(), nums.end());

    std::cout << total << std::endl;
}

int main() {
	using std::cout; using std::cin; using std::string;

    int cases;
    cin >> cases;
    
    while (cases--) solve();

	return 0;
}
