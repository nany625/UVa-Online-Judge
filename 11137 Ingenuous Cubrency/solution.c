#include <stdio.h>

long dp[10000];
int coins[21];

int main() {
    for(int i = 1; i <= 21; ++i)
        coins[i - 1] = i * i * i;
    dp[0] = 1;
    for(int i = 0; i < 21; ++i) {
        for(int j = coins[i]; j <= 9999; ++j)
            dp[j] += dp[j - coins[i]];
    }
    int n;
    while(scanf("%d", &n) == 1)
        printf("%ld\n", dp[n]);
	return 0;
}
