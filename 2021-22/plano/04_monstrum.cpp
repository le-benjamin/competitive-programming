#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    vector<char> stk;
    map<char, char> m = {{'(',')'}, {'{','}'}, {'[',']'}, {'<','>'}};
    
    char c;
    while (cin >> c) {
        if (m.find(c) != m.end()) stk.push_back(c);
        else if (stk.size() == 0) { stk.push_back(c); break; }
        else if (c == m[stk.back()]) stk.pop_back();
        else break;
    }
    
    if (stk.size() > 0) cout << "You will get eaten.\n";
    else cout << "The beasts shall tremble!\n";
    
    return 0;
}
