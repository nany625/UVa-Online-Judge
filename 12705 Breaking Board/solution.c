#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count[36], costs[] = {
    2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 
    6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 
    7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 
    10, 10, 10, 11, 11, 12
};

int compare(const void *a, const void *b) {
    return *(int*)a < *(int*)b;
}

int main() {
    int T;
    scanf("%d ", &T);
    char L[102];
    while(T--) {
        fgets(L, sizeof(L), stdin);
        memset(count, 0, sizeof(count));
        int len = strlen(L);
        for(int i = 0; i < len; ++i) {
            if(isdigit(L[i]))
                ++count[L[i] - '0'];
            else if(isupper(L[i]))
                ++count[L[i] - 'A' + 10];
        }
        qsort(count, 36, sizeof(int), compare);
        int minCost = 0;
        for(int i = 0; i < 36 && count[i] > 0; ++i)
            minCost += count[i] * costs[i];
        printf("%d\n", minCost);
    }
    return 0;
}
