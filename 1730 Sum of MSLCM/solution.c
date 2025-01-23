#include <stdio.h>
#define MAX_NUM 20000000

long ans[MAX_NUM + 1];

void init() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        for(int i = n; i <= MAX_NUM; i += n)
            ans[i] += n;
    }
    for(int n = 3; n <= MAX_NUM; ++n)
        ans[n] += ans[n - 1];
}

int main() {
    init();
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%ld\n", ans[N] + N - 1);
    return 0;
}
