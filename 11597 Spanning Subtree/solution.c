#include <stdio.h>

int main() {
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0)
        printf("Case %d: %d\n", ++cases, n >> 1);
    return 0;
}
