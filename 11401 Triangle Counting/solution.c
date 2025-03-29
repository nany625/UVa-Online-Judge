#include <stdio.h>
#define MAXN 1000000

long ans[MAXN + 1];

int main() {
    for(int n = 4; n <= MAXN; ++n) {
        long temp = (n >> 1) - 1;
        ans[n] = ans[n - 1] + (1 + temp) * temp - temp * ((n + 1) & 1);
    }
    int n;
    while(scanf("%d", &n) && n >= 3)
        printf("%ld\n", ans[n]);
	return 0;
}
