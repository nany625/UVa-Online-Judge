#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude, length;
} DP;

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(array[mid] > key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int cases;
    scanf("%d", &cases);
    getchar();
    getchar();
    char buffer[12];
	while(cases--) {
	    DP *dp = NULL;
	    int size = 0;
	    while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
	        dp = (DP*)realloc(dp, (size + 1) * sizeof(DP));
	        dp[size++].altitude = atoi(buffer);
	    }
	    int *lis = NULL, lisSize = 0;
	    for(int i = size - 1; i >= 0; --i) {
	        dp[i].length = binarySearch(lis, lisSize, dp[i].altitude);
	        if(dp[i].length == lisSize)
	            lis = (int*)realloc(lis, ++lisSize * sizeof(int));
	        lis[dp[i].length] = dp[i].altitude;
	    }
	    printf("Max hits: %d\n", lisSize);
	    int i = lisSize - 1;
	    for(int j = 0; i >= 0; ++j) {
	        if(dp[j].length == i) {
	            printf("%d\n", dp[j].altitude);
	            --i;
	        }
	    }
	    free(dp);
	    free(lis);
	    if(cases)
	        putchar('\n');
	}
	return 0;
}
