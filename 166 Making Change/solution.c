#include <stdio.h>
#include <stdbool.h>
#define MAX_AMOUNT 100
#define EXTRA 39

int coins[] = {1, 2, 4, 10, 20, 40}, amount[6], dp[MAX_AMOUNT + EXTRA + 1], change[EXTRA + 1];

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
    for(int i = 1; i <= EXTRA; ++i) {
        change[i] = EXTRA + 1;
        for(int j = 0; j < 6; ++j) {
            if(i >= coins[j])
                change[i] = change[i] < change[i - coins[j]] + 1 ? change[i] : change[i - coins[j]] + 1;
        }
    }
    while(!lastCase()) {
        double value;
        scanf("%lf", &value);
        value *= 20;
        for(int i = 1; i <= value + EXTRA; ++i)
            dp[i] = MAX_AMOUNT + EXTRA + 1;
        dp[0] = 0;
        for(int i = 0; i < 6; ++i) {
            while(amount[i]--) {
                for(int j = value + EXTRA; j >= coins[i]; --j) {
                    if(dp[j - coins[i]] != MAX_AMOUNT + EXTRA + 1)
                        dp[j] = dp[j] < dp[j - coins[i]] + 1 ? dp[j] : dp[j - coins[i]] + 1;
                }
            }
        }
        int min = MAX_AMOUNT + EXTRA + 1;
        for(int i = value; i <= value + EXTRA; ++i) {
            if(dp[i] != MAX_AMOUNT + EXTRA + 1)
                min = min < dp[i] + change[i - (int)value] ? min : dp[i] + change[i - (int)value];
        }
        printf("%3d\n", min);
    }
	return 0;
}
