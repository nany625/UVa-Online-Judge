#include <stdio.h>

long dp[6001];
int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

int main() {
    dp[0] = 1;
    for(int i = 0; i < 11; ++i) {
        for(int j = coins[i]; j <= 6000; ++j)
            dp[j] += dp[j - coins[i]];
    }
    int a, b;
    while(scanf("%d.%d", &a, &b) && a + b > 0)
        printf("%3d.%02d%17ld\n", a, b, dp[20 * a + b / 5]);
	return 0;
}
