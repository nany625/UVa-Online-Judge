#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int s, d;
        scanf("%d %d", &s, &d);
        if(s < d || (s + d) % 2 == 1)
            puts("impossible");
        else
            printf("%d %d\n", (s + d) / 2, (s - d) / 2);
    }
    return 0;
}
