#include <stdio.h>

long dp[30001];
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main() {
    dp[0] = 1;
    for(int i = 0; i < 11; ++i) {
        for(int j = coins[i]; j <= 30000; ++j)
            dp[j] += dp[j - coins[i]];
    }
    double amount;
    while(scanf("%lf", &amount) && amount != 0)
        printf("%6.2lf%17ld\n", amount, dp[(int)(amount * 100 + 0.1)]);
	return 0;
}
