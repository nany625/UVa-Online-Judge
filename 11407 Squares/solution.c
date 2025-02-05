#include <stdio.h>
#define MAX_AMOUNT 10000

int dp[MAX_AMOUNT + 1], coins[100];

int main() {
    for(int n = 1; n <= 100; ++n)
        coins[n - 1] = n * n;
    for(int i = 1; i <= MAX_AMOUNT; ++i) {
        dp[i] = MAX_AMOUNT;
        for(int j = 0; j < 100; ++j) {
            if(i >= coins[j])
                dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
    return 0;
}
