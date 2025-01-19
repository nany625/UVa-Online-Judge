#include <stdio.h>

int main() {
    int cases = 0, N;
    while(scanf("%d", &N) && N != 0) {
        long redComb = N / 3 - 1;
        long ans = (((N << 1) - 11 >> 1) + ((N << 1) - (redComb >> 1) * 12 + 1 >> 1)) * (redComb >> 1) >> 1;
        if(redComb & 1) {
            if(N & 1)
                ans += (N - (redComb >> 1) * 6 - 5) >> 1;
            else
                ans += (N - 3 * redComb) >> 1;
        }
        printf("Case %d: %ld\n", ++cases, ans);
    }
	return 0;
}
