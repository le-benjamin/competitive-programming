#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    vector<int> count(n, 0);
    bool i = false, c = false;
    scanf("%d", &count[0]);
    for (int j = 1; j < n; j++) { 
        scanf("%d", &count[j]);
        if (count[j-1] - count[j] > 1) i = 1;
        else if (count[j-1] - count[j] < 0) c = 1;
    }
    
    if (i && c) printf("Ahhh! So many cheaters!\n");
    else if (i) printf("Oh no! Looks like the impostor cheated!\n");
    else if (c) printf("Oh dang! A crewmate cheated!\n");
    else printf("Whew! Looks like a safe game");
    
    return 0;
}
