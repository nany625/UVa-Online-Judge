#include <stdio.h>

typedef struct {
    short P, W;
} Object;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N;
	    scanf("%d", &N);
	    Object objects[N];
	    for(int i = 0; i < N; ++i)
	        scanf("%hd %hd", &objects[i].P, &objects[i].W);
	    int G;
	    scanf("%d", &G);
	    short MW[G], capacity = 0;
	    for(int i = 0; i < G; ++i) {
	        scanf("%hd", &MW[i]);
	        capacity = capacity > MW[i] ? capacity : MW[i];
	    }
	    int dp[capacity + 1];
	    memset(dp, 0, sizeof(dp));
	    for(int i = 0; i < N; ++i) {
	        short p = objects[i].P;
	        short w = objects[i].W;
	        for(int j = capacity; j >= w; --j)
	            dp[j] = dp[j] > dp[j - w] + p ? dp[j] : dp[j - w] + p;
	    }
	    int maxValue = 0;
	    for(int i = 0; i < G; ++i)
	        maxValue += dp[MW[i]];
	    printf("%d\n", maxValue);
	}
	return 0;
}
