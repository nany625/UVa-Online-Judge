#include <stdio.h>
#include <string.h>
#define MAX_AMOUNT 19997

int dp[MAX_AMOUNT + 1];

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int price, n;
        scanf("%d %d", &price, &n);
        int coins[n], sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &coins[i]);
            if(sum < price)
                sum += coins[i];
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = sum; j >= coins[i]; --j) {
                if(dp[j - coins[i]] != -1) {
                    if(dp[j] == -1)
                        dp[j] = dp[j - coins[i]] + 1;
                    else
                        dp[j] = dp[j] < dp[j - coins[i]] + 1 ? dp[j] : dp[j - coins[i]] + 1;
                }
            }
        }
        while(dp[price] == -1)
            ++price;
        printf("%d %d\n", price, dp[price]);
    }
	return 0;
}
