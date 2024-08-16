#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int exchange = (n - 3) / 2 + 1;
        printf("%d\n", exchange + (n - 2 * exchange) % 3 / 2);
    }
    return 0;
}
