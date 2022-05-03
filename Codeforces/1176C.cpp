#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
    int n;
    scanf("%d", &n);
    if (n < 6) {
        printf("%d\n", n);
        return 0;
    }

    arr.resize(n, 0);

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    int cnt[6] = {0};

    for (int i = 0; i < n; i++) {
        if (arr[i] == 4) cnt[0]++;
        if (arr[i] == 8)
            if (cnt[0] > cnt[1]) cnt[1]++;
        if (arr[i] == 15)
            if (cnt[1] > cnt[2]) cnt[2]++;
        if (arr[i] == 16)
            if (cnt[2] > cnt[3]) cnt[3]++;
        if (arr[i] == 23)
            if (cnt[3] > cnt[4]) cnt[4]++;
        if (arr[i] == 42)
            if (cnt[4] > cnt[5]) cnt[5]++;
    }
    
    printf("%d\n", n-cnt[5]*6);

    return 0;
}