#include <stdio.h>

int main() {
    int n, t;
    char line[55];
    scanf("%d %d", &n, &t);
    scanf("%s", line);

    while (t--) 
        for (int i = 0; i < n-1; i++)
            if (line[i] == 'B' && line[i+1] == 'G') {
                line[i] = 'G';
                line[i+++1] = 'B';
            }

    printf("%s\n", line);
    return 0;
}