#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d\n", &n);

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    while (n--) {
        char *s = (char*)malloc(sizeof(char)*250);
        char *out = (char*)malloc(sizeof(char)*250);
        scanf("%s\n", s);
        int outIndex = 0;

        for (int i = 1; i < (int)strlen(s); i++)
            if (find(begin(vowels), end(vowels), s[i-1]) != end(vowels))
                out[outIndex++] = s[i++];

        printf("%s\n", out);
    }

    return 0;
}