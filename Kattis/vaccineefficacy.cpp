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

    int n;
    cin >> n;

    double control = 0, vax = 0;
    int ca = 0, cb = 0, cc = 0, va = 0, vb = 0, vc = 0;
    for (int m = 0; m < n; m++) {
        char v, a, b, c;
        cin >> v >> a >> b >> c;
        if (v == 'N') {
            control++;
            if (a == 'Y') ca++;
            if (b == 'Y') cb++;
            if (c == 'Y') cc++;
        } else {
            vax++;
            if (b == 'Y') vb++;
            if (c == 'Y') vc++;
            if (a == 'Y') va++;
        }
    }
    double ea, eb, ec;

    ea = (ca > 0) ? ((ca/control)-(va/vax))/(ca/control)*100 : -1;
    eb = (cb > 0) ? ((cb/control)-(vb/vax))/(cb/control)*100 : -1;
    ec = (cc > 0) ? ((cc/control)-(vc/vax))/(cc/control)*100 : -1;
    cout << ((ea <= 0) ? "Not Effective" : std::to_string(ea)) << std::endl;
    cout << ((eb <= 0) ? "Not Effective" : std::to_string(eb)) << std::endl;
    cout << ((ec <= 0) ? "Not Effective" : std::to_string(ec)) << std::endl;

	return 0;
}
