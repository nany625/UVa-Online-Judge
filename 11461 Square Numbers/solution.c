#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) && a != 0 && b != 0)
        printf("%d\n", (int)sqrt(b) - (int)ceil(sqrt(a)) + 1);
    return 0;
}
