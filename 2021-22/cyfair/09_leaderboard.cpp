#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, pair<int, int>>& a, pair<string, pair<int, int>>& b) {
    if (a.second.first != b.second.first) return a.second.first > b.second.first;
    if (a.second.second != b.second.second) return a.second.second > b.second.second;
    return a.first < b.first;
}

bool cmp2(pair<string, pair<int, int>>& a, pair<string, pair<int, int>>& b) {
    return a.second.first == b.second.first && a.second.second == b.second.second;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<string, pair<int, int>>> names;
    
    for (int i = 0; i < n; i++) {
        string name;
        int im, cr;
        cin >> name >> im >> cr;
        names.push_back({name, {im, cr}});
    }
    
    sort(names.begin(), names.end(), cmp);
    
    int place = 1;
    int truePlace = 1;
    cout << place << ". " << names[0].first << '\n';
    vector<pair<string, pair<int, int>>> winners;
    winners.push_back(names[0]);
    for (int i = 1; i < (int)names.size(); i++) {
        truePlace++;
        if (!cmp2(names[i], names[i-1])) place = truePlace;
        if (place == 1) winners.push_back(names[i]);
        cout << place << ". " << names[i].first << '\n';
    }
    cout << "Congratulations ";
    for (pair<string, pair<int, int>> a : winners)
        cout << a.first << ", ";
    cout << "you got the big dub!!!\n";
    
    return 0;
}
