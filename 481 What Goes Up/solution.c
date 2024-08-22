#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lastIndex, lis;
} DP;

int binarySearch(DP *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid].lis < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
	int *sequence = NULL, size = 0, num;
	while(scanf("%d", &num) == 1) {
	    sequence = (int*)realloc(sequence, (size + 1) * sizeof(int));
	    sequence[size++] = num;
	}
	DP *dp = NULL;
	int predecessor[size], lisSize = 0;
	for(int i = 0; i < size; ++i) {
	    int pos = binarySearch(dp, lisSize, sequence[i]);
	    if(pos == lisSize)
	        dp = (DP*)realloc(dp, ++lisSize * sizeof(DP));
	    dp[pos].lastIndex = i;
	    dp[pos].lis = sequence[i];
	    predecessor[i] = pos > 0 ? dp[pos - 1].lastIndex : -1;
	}
	int ans[lisSize], i = dp[lisSize - 1].lastIndex;
	for(int j = lisSize - 1; j >= 0; --j) {
	    ans[j] = sequence[i];
	    i = predecessor[i];
	}
	printf("%d\n-\n", lisSize);
	for(i = 0; i < lisSize; ++i)
	    printf("%d\n", ans[i]);
	free(sequence);
	free(dp);
	return 0;
}
