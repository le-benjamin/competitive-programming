#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[3] = {0};
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            arr[a%3]++;
        }
        int amt = min(arr[1], arr[2]);
        arr[0] += (arr[1]-amt)/3 + (arr[2]-amt)/3 + amt;
        
        printf("%d\n", arr[0]);
    }
}