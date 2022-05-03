#include <bits/stdc++.h>
using namespace std;

char *ConvUpper(char* str, int len) {
    char *out = (char*)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
        out[i] = toupper(str[i]);
    return out;
}


int main() {
    int n;
    scanf("%d\n", &n);
    vector<char*> sus;
    while (n--) {
        char *name = (char*)malloc(sizeof(char) * 50), *task = (char*)malloc(sizeof(char) * 50);
        double time;
        scanf("%[^,], %[^,], %lf\n", name, task, &time);
        name = ConvUpper(name, strlen(name));
        task = ConvUpper(task, strlen(task));
        
        int a = 0;
        for (int i = 0; i < (int)strlen(task); i++) {
            char c = task[i];
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                a++;
        }
        double l = 0, r = 1000, x = 0;
        while (r-l > 0.0001) {
            x = (r+l)/2;
            double eq1 = (x+a)*log(x);
            double eq2 = time*a;
            if (eq1 == eq2) break;
            else if (eq1 > eq2) r = x;
            else l = x;
        }
        if ((int)(l*1000)%10 == 0) sus.push_back(name);
    }
    if (sus.size() == 0) printf("No one is an imposter, vote to skip.\n");
    else if (sus.size() == 1) printf("%s IS AN IMPOSTER!\n", sus[0]);
    else if (sus.size() == 2) printf("%s AND %s ARE IMPOSTERS!\n", sus[0], sus[1]);
    else
        for (int i = 0; i < (int)sus.size(); i++)
            if (i < (int)sus.size()-1) printf("%s, ", sus[i]);
            else printf("AND %s ARE IMPOSTERS!", sus[i]);
    return 0;
}
