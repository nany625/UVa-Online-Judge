#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool dp[2][100];

int main() {
    int M;
    scanf("%d", &M);
    while(M--) {
        int N, K;
        scanf("%d %d", &N, &K);
        memset(dp[0], 0, sizeof(dp[0]));
        int num;
        scanf("%d", &num);
        num = (num % K + K) % K;
        dp[0][num] = true;
        for(int i = 1; i < N; ++i) {
            scanf("%d", &num);
            num = (num % K + K) % K;
            if(i & 1) {
            	memset(dp[1], 0, sizeof(dp[1]));
            	for(int j = 0; j < K; ++j) {
	                if(dp[0][j])
	                    dp[1][(j + num) % K] = dp[1][(j + K - num) % K] = true;
	            }
            } else {
            	memset(dp[0], 0, sizeof(dp[0]));
            	for(int j = 0; j < K; ++j) {
	                if(dp[1][j])
	                    dp[0][(j + num) % K] = dp[0][(j + K - num) % K] = true;
	            }
            }
        }
        puts(dp[(N - 1) & 1][0] ? "Divisible" : "Not divisible");
    }
	return 0;
}
