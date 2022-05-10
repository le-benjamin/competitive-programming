/*
ID: b.le611
PROG: gift1
LANG: C++
*/
#include <fstream>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");

    int np;
    fin >> np;

    string friends[15];
    map<string, int> money;

    
    for (int i = 0; i < np; i++) {
        fin >> friends[i];
        money[friends[i]] = 0;
    } 

    
    for (int i = 0; i < np; i++) {
        string giver;
        int amt, peopleNum;
        fin >> giver >> amt >> peopleNum;
        if (!peopleNum) continue;
        money[giver] -= amt - amt%peopleNum;
        for (int j = 0; j < peopleNum; j++) {
            string name;
            fin >> name;
            money[name] += amt/peopleNum;
        }
    }

    for (int i = 0; i < np; i++)
        fout << friends[i] + ' ' << money[friends[i]] << '\n';

    return 0;
}