#include <stdio.h>
#define MAX_AMOUNT 7489

int dp[MAX_AMOUNT + 1] = {1}, coins[] = {1, 5, 10, 25, 50};

int main() {
    for(int i = 0; i < 5; ++i) {
        for(int j = coins[i]; j <= MAX_AMOUNT; ++j)
            dp[j] += dp[j - coins[i]];
    }
    int money;
    while(scanf("%d", &money) == 1)
        printf("%d\n", dp[money]);
    return 0;
}
