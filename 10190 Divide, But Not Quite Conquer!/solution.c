#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n <= 1 || m <= 1) {
            puts("Boring!");
            continue;
        }
        int *a = (int*)malloc(sizeof(int)), size = 1;
        a[0] = n;
        while(n % m == 0) {
            a = (int*)realloc(a, (size + 1) * sizeof(int));
            a[size++] = n / m;
            n /= m;
        }
        if(n != 1)
            puts("Boring!");
        else {
            for(int i = 0; i < size - 1; ++i)
                printf("%d ", a[i]);
            puts("1");
        }
        free(a);
    }
    return 0;
}
