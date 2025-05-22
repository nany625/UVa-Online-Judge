#include <stdio.h>
#include <string.h>

typedef struct {
    int weight, value;
} Item;

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) {
        Item items[n];
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &items[i].weight, &items[i].value);
        if(m > 1800)
            m += 200;
        int dp[m + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = m; j >= items[i].weight; --j) {
                if(dp[j - items[i].weight] != -1)
                    dp[j] = dp[j] > dp[j - items[i].weight] + items[i].value ? dp[j] : dp[j - items[i].weight] + items[i].value;
            }
        }
        int max = -1;
        if(m > 2200) {
            for(int i = 0; i <= m; ++i)
                max = max > dp[i] ? max : dp[i];
        } else if(m > 2000) {
            for(int i = 2001; i <= m; ++i)
                max = max > dp[i] ? max : dp[i];
            m -= 200;
            for(int i = 0; i <= m; ++i)
                max = max > dp[i] ? max : dp[i];
        } else {
            for(int i = 0; i <= m; ++i)
                max = max > dp[i] ? max : dp[i];
        }
        printf("%d\n", max);
    }
	return 0;
}
