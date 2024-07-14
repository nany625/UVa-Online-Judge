#include <stdio.h>

int main() {
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("f91(%d) = %d\n", N, N >= 101 ? N - 10 : 91);
    return 0;
}
