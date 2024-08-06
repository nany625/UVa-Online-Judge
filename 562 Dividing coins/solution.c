#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int m;
        scanf("%d", &m);
        int coins[m], sum = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &coins[i]);
            sum += coins[i];
        }
        int temp = sum / 2, max = 0;
        bool subsetSum[temp + 1];
        subsetSum[0] = true;
        for(int i = 1; i <= temp; ++i)
            subsetSum[i] = false;
        for(int i = 0; i < m && max < temp; ++i) {
            for(int j = temp; j >= coins[i] && max < temp; --j) {
                if(subsetSum[j - coins[i]]) {
                    subsetSum[j] = true;
                    max = max > j ? max : j;
                }
            }
        }
        printf("%d\n", sum - 2 * max);
    }
	return 0;
}
