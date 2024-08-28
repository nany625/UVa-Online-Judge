#include <stdio.h>
#include <math.h>

int main() {
    int s;
    while(scanf("%d", &s) && s != 0) {
        int pages = ((int)(-1 + sqrt(1 + (s << 3))) >> 1) + 1;
        printf("%d %d\n", ((pages + 1) * pages >> 1) - s, pages);
    }
    return 0;
}
