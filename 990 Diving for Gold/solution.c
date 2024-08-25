#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int d, v;
} Treasure;

int main() {
	int t, w;
	bool firstCase = true;
	while(scanf("%d %d", &t, &w) == 2) {
	    if(!firstCase)
	        putchar('\n');
	    int n;
	    scanf("%d", &n);
	    Treasure treasures[n];
	    for(int i = 0; i < n; ++i)
	        scanf("%d %d", &treasures[i].d, &treasures[i].v);
	    int dp[t + 1];
	    memset(dp, 0, sizeof(dp));
	    bool selected[n][t + 1];
	    memset(selected, 0, sizeof(selected));
	    for(int i = 0; i < n; ++i) {
	        int d = 3 * w * treasures[i].d;
	        int v = treasures[i].v;
	        for(int j = t; j >= d; --j) {
	            if(dp[j] < dp[j - d] + v) {
	                dp[j] = dp[j - d] + v;
	                selected[i][j] = true;
	            }
	        }
	    }
	    printf("%d\n", dp[t]);
	    int currentT = t, *treasureID = NULL, size = 0;
	    for(int i = n - 1; i >= 0; --i) {
	        if(selected[i][currentT]) {
	            treasureID = (int*)realloc(treasureID, (size + 1) * sizeof(int));
	            treasureID[size++] = i;
	            currentT -= 3 * w * treasures[i].d;
	        }
	    }
	    printf("%d\n", size);
	    for(int i = size - 1; i >= 0; --i)
	        printf("%d %d\n", treasures[treasureID[i]].d, treasures[treasureID[i]].v);
	    free(treasureID);
	    firstCase = false;
	}
	return 0;
}
