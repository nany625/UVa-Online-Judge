#include <stdio.h>

long dp[10000];
int coins[] = {
    1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 
    1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 
    9261
};

int main() {
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
