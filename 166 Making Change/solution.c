#include <stdio.h>
#include <stdbool.h>
#define MAX_AMOUNT 140

int coins[] = {1, 2, 4, 10, 20, 40}, amount[6], dp[MAX_AMOUNT + 1], change[41];

bool lastCase() {
    bool result = true;
    for(int i = 0; i < 6; ++i) {
        scanf("%d", &amount[i]);
        if(amount[i] > 0)
            result = false;
    }
    return result;
}

int main() {
    for(int i = 1; i <= 40; ++i) {
        change[i] = 41;
        for(int j = 0; j < 6; ++j) {
            if(i >= coins[j])
                change[i] = change[i] < change[i - coins[j]] + 1 ? change[i] : change[i - coins[j]] + 1;
        }
    }
    while(!lastCase()) {
        double value;
        scanf("%lf", &value);
        value *= 20;
        for(int i = 1; i <= value + 40; ++i)
            dp[i] = MAX_AMOUNT + 1;
        dp[0] = 0;
        for(int i = 0; i < 6; ++i) {
            while(amount[i]--) {
                for(int j = value + 40; j >= coins[i]; --j) {
                    if(dp[j - coins[i]] != MAX_AMOUNT + 1)
                        dp[j] = dp[j] < dp[j - coins[i]] + 1 ? dp[j] : dp[j - coins[i]] + 1;
                }
            }
        }
        int min = MAX_AMOUNT;
        for(int i = value; i <= value + 40; ++i) {
            if(dp[i] != MAX_AMOUNT + 1)
                min = min < dp[i] + change[i - (int)value] ? min : dp[i] + change[i - (int)value];
        }
        printf("%3d\n", min);
    }
	return 0;
}
