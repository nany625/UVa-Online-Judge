#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int s, d;
        scanf("%d %d", &s, &d);
        if(s < d || ((s + d) & 1))
            puts("impossible");
        else
            printf("%d %d\n", (s + d) >> 1, (s - d) >> 1);
    }
    return 0;
}
