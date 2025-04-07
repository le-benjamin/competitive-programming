#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define vt vector

struct cmp {
    bool operator() (const string& a, const string& b) const {
        string del = ".";
        int start1, end1 = -1*del.size();
        int start2, end2 = -1*del.size();
        do {
            start1 = end1+del.size();
            end1 = a.find(del, start1);
            start2 = end2+del.size();
            end2 = b.find(del, start2);
            if (stoi(a.substr(start1, end1-start1)) < stoi(b.substr(start2, end2-start2))) return true;
            else if (stoi(a.substr(start1, end1-start1)) > stoi(b.substr(start2, end2-start2))) return false;
        } while (end1 != -1 && end2 != -1);
        return false;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--) {
        map<string, set<string>, cmp> m;
        int x; cin >> x;
        while (x--) {
            string ip, mac; cin >> ip >> mac;
            m[ip].insert(mac);
        }
        for (auto v : m) {
            cout << v.first << ' ' << v.second.size() << '\n';
        }
    }

    return 0;
}