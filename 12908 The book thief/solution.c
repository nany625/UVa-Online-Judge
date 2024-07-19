#include <stdio.h>
#include <math.h>

int main() {
    int s;
    while(scanf("%d", &s) && s != 0) {
        int pages = (-1 + sqrt(1 + 8 * s)) / 2 + 1;
        printf("%d %d\n", (pages + 1) * pages / 2 - s, pages);
    }
    return 0;
}
