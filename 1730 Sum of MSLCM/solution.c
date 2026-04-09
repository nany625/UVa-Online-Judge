#include <stdio.h>
#include <math.h>

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        long limit = sqrt(N), quotients[limit + 1], ans = -1;
        for(int i = 1; i <= limit; ++i) {
            quotients[i] = N / i;
            ans += i * quotients[i];
        }
        for(int i = 1; i < limit; ++i)
            ans += i * (quotients[i] + quotients[i + 1] + 1) * (quotients[i] - quotients[i + 1]) >> 1;
        if(limit != quotients[limit])
            ans += limit * (quotients[limit] + N / (limit + 1) + 1) * (quotients[limit] - N / (limit + 1)) >> 1;
        printf("%ld\n", ans);
    }
    return 0;
}
