#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define vt vector

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    map<char, int> val;
    val['A'] = 0; val['D'] = 1; 
    val['F'] = 2; val['G'] = 3; 
    val['V'] = 4; val['X'] = 5; 

    int tc; cin >> tc;
    while (tc--) {
        map<char, string> m;
        vector<string> table(6, "");
        for (auto& x : table) cin >> x;
        string key, skey; cin >> key;
        skey = key; sort(skey.begin(), skey.end());
        string en; cin >> en;
        string de1, de2;
        int thing = en.size()/key.size()*key.size();
        for (int i = 0; i < thing; i++) m[skey[i%(key.size())]] += en[i];
        string skey2 = key.substr(0, en.size()-thing); sort(skey2.begin(), skey2.end());
        for (int i = thing; i < en.size(); i++) m[skey2[i%key.size()]] += en[i];
        for (int i = 0; i < en.size(); i++) de1 += m[key[i%key.size()]][i/key.size()];
        for (int i = 0; i < de1.size(); i++) de2 += table[val[de1[i]]][val[de1[++i]]];
        cout << de2 << '\n';
    }

    return 0;
}