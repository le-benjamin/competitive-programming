#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>

#define vt std::vector
#define pb push_back
#define ll long long
#define PI 3.1415926535897932

int main() {
	using std::cout; using std::cin; using std::string;

    int n, m;
    cin >> n >> m;

    vt<string> fb;
    for (int i = 1; i <= m; i++) {
        string out = "";
        if (!(i%3)) out += "fizz";
        if (!(i%5)) out += "buzz";
        if (out.length() < 1) out = std::to_string(i);
        fb.pb(out);
    }

    int bestCan = 0, bestScore = INT_MIN;

    for (int can = 1; can <= n; can++) {
        int score = 0;

        for (int i = 0; i < m; i++) {
            string word;
            cin >> word;
            if (word == fb[i]) score++;
            else score--;
        }

        if (score > bestScore) {
            bestCan = can;
            bestScore = score;
        }
    }

    cout << bestCan << std::endl;

	return 0;
}
