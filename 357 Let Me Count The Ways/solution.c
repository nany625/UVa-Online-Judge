#include <stdio.h>
#define MAX_AMOUNT 30000

long dp[MAX_AMOUNT + 1] = {1};
int coins[] = {1, 5, 10, 25, 50};

int main() {
    for(int i = 0; i < 5; ++i) {
        for(int j = coins[i]; j <= MAX_AMOUNT; ++j)
            dp[j] += dp[j - coins[i]];
    }
    int n;
    while(scanf("%d", &n) == 1) {
        if(dp[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %ld ways to produce %d cents change.\n", dp[n], n);
    }
    return 0;
}
