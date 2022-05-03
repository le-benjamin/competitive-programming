#include <stdio.h>
#include <stdlib.h> // abs()

int main() {
    int even, odd;
    scanf("%d %d", &even, &odd);
    
    if (!(even || odd)) printf("NO\n");
    else if (abs(even-odd) <= 1) printf("YES\n");
    else printf("NO\n");

    return 0;
}