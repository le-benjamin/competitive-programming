/*
ID: b.le611
TASK: milk
LANG: C++                 
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<int, int>> milks; // first = price, second = quantity

    for (int farmer = 0; farmer < m; farmer++) {
        int p, a;
        scanf("%d %d", &p, &a);
        milks.push_back({p, a});
    }
    sort(milks.begin(), milks.end(), cmp);

    int cost = 0;

    for (int i = 0; i < milks.size(); i++) {
        int p = milks[i].first, q = milks[i].second;
        n -= q;
        cost += q*p;
        if (n < 0) {
            cost += n*p;
            break;
        }
        if (n == 0) break;
    }

    printf("%d\n", cost);

    return 0;
}