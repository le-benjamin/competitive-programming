#include <bits/stdc++.h>
using namespace std;

#define N 14

int solve() {
    int out = 0; 

    int n; cin >> n;
    int no[N][N], so[N][N], we[N][N], ea[N][N], ne[N][N];

    for (int i = 0; i < 5; i++) {
        string type; cin >> type;

        if (type == "N") {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> no[i][j];
                }
            }
        } else if (type == "S") {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> so[i][j];
                }
            }
        } else if (type == "W") {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> we[i][j];
                }
            }
        } else if (type == "E") {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> ea[i][j];
                }
            }
        } else if (type == "neighbours") {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> ne[i][j];
                }
            }
        }
    }
    
    

    cout << "n-s\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << n - no[i][j] - so[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "w-e\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << n - we[i][j] - ea[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "ne\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ne[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "\n\n";


    return out;
}

int main() {
    freopen("buildings.in", "r", stdin);
    freopen("buildings.out", "w", stdout);
    int tc; cin >> tc;

    for (int i = 1; i <= tc; i++) 
        cout << "Case #" << i << ": " << solve() << '\n';

    return 0;
}