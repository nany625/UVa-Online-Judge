#include <stdio.h>

int problems[12];

int main() {
    int X = 0, S;
    while(scanf("%d", &S) && S >= 0) {
        printf("Case %d:\n", ++X);
        for(int i = 0; i < 12; ++i)
            scanf("%d", &problems[i]);
        int requirement, total = 0;
        for(int i = 0; i < 12; ++i) {
            scanf("%d", &requirement);
            if(S >= total + requirement) {
                puts("No problem! :D");
                total += requirement;
            } else
                puts("No problem. :(");
            S += problems[i];
        }
    }
    return 0;
}
