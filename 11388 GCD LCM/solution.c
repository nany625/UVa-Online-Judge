#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int G, L;
        scanf("%d %d", &G, &L);
        if(L % G == 0)
            printf("%d %d\n", G, L);
        else
            puts("-1");
    }
    return 0;
}
