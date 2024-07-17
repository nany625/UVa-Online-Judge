#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        if((n - m) % (m - 1) == 0)
            printf("%d\n", (n - m) / (m - 1) + 1);
        else
            puts("cannot do this");
    }
    return 0;
}
