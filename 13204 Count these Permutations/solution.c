#include <stdio.h>
#define MAXN 1000000
#define MOD 1000000007

long ans[MAXN + 1] = {0, 1, 1};

int main() {
	for(int n = 3; n <= MAXN; ++n) {
		if(n & 1)
			ans[n] = ans[n - 1] * n % MOD;
		else
			ans[n] = ans[n - 2] * (n >> 1) % MOD * (n >> 1) % MOD;
	}
	int n;
	while(scanf("%d", &n) == 1)
		printf("%ld\n", ans[n]);
	return 0;
}
