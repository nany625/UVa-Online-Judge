#include <stdio.h>
#define MOD 1000000007

long bigMod(long N) {
    if(N == 0)
        return 1;
    if(N == 1)
        return 2;
    long temp = bigMod(N >> 1);
    if(N & 1)
        return temp * temp % MOD << 1;
    return temp * temp % MOD;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        long N;
        scanf("%ld", &N);
        printf("Case #%d: %ld\n", i, N * bigMod(N - 1) % MOD);
    }
	return 0;
}
