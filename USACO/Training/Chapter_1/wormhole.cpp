/*
ID: b.le611
PROG: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

void setIO(string name = "") {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout); 
}

int n, cnt = 0;
vt<pair<int, int>> coords = {};
vt<int> links = {};
vt<int> rights = {};

bool isInfinite() {
    int skip = 0, vst = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (skip&(1<<i)) continue;
        vst = 0;
        j = i;
        while (1) {
            if (vst&(1<<j)) return true;
            vst|=1<<j;
            skip|=1<<j;
            j = rights[links[j]];
            if (j == -1) break;
        }
    }
    return false;
}

int solve() {
    int cnt = 0;
    int unlinked = find(all(links), -1)-links.begin();
    
    if (unlinked == n) 
        if (isInfinite()) return 1;
        else return 0;

    for (int i = unlinked+1; i < n; i++) {
        if (links[i] != -1) continue;
        links[i] = unlinked;
        links[unlinked] = i;
        cnt += solve();
        links[unlinked] = links[i] = -1;
    }

    return cnt;
}

int main() {
    setIO("wormhole");
	
	scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        coords.eb(0, 0);
        scanf("%d %d", &coords[i].first, &coords[i].second);
        rights.pb(-1);
        links.pb(-1);
    }

    sort(all(coords), [](auto& a, auto& b) { return a.second < b.second || a.second == b.second && a.first < b.first; });
    for (int i = 0; i < n-1; i++) if (coords[i].second == coords[i+1].second) rights[i] = i+1;

    int cnt = solve();

    printf("%d\n", cnt);

	return 0;
}