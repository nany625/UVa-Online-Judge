#include <stdio.h>
#include <string.h>

unsigned int dp[2][4];

int get(int row, int num) {
    return dp[row][num >> 5] & (1u << (num & 31));
}

void set(int row, int num) {
    dp[row][num >> 5] |= 1u << (num & 31);
}

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
        set(0, num);
        for(int i = 1; i < N; ++i) {
            scanf("%d", &num);
            num = (num % K + K) % K;
            memset(dp[i & 1], 0, sizeof(dp[i & 1]));
            for(int j = 0; j < K; ++j) {
	            if(get(!(i & 1), j)) {
	                set(i & 1, (j + num) % K);
	                set(i & 1, (j + K - num) % K);
	            }
	        }
        }
        puts(get((N - 1) & 1, 0) ? "Divisible" : "Not divisible");
    }
	return 0;
}
