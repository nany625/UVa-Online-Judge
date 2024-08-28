#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int exchange = ((n - 3) >> 1) + 1;
        printf("%d\n", exchange + (((n - (exchange << 1)) % 3) >> 1));
    }
    return 0;
}
