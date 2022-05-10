/*
ID: b.le611
PROG: barn1
LANG: C++
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    
    int m, s, c;
    scanf("%d %d %d", &m, &s, &c);

    vector<pair<int, int>> barn;
    for (int i = 0; i < c; i++) {
        int num;
        scanf("%d", &num);
        barn.push_back({num, num});
    }

    sort(barn.begin(), barn.end(), cmp);
    
    while (barn.size() > m) {
        // find min dist between intervals - 1 for loop, store indexes of intervals
        // merge said dist 

        int pos = 0;;
        int minDist = 500;

        for (int i = 0; i < barn.size()-1; i++) {
            if (barn[i+1].first-barn[i].second < minDist) {
                minDist = barn[i+1].first-barn[i].second;
                pos = i;
            }
        }

        barn[pos].second = barn[pos+1].second;
        barn.erase(barn.begin()+pos+1);
    }

    int sum = 0;
    for (pair<int, int> i : barn) sum += i.second-i.first+1; // add 1, subtraction not inclusive 
    
    printf("%d\n", sum);

    return 0;
}

