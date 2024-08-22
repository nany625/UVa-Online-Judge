#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid] < key)
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
	int dp[size], *lis = NULL, lisSize = 0;
	for(int i = 0; i < size; ++i) {
	    int pos = binarySearch(lis, lisSize, sequence[i]);
	    if(pos == lisSize)
	        lis = (int*)realloc(lis, ++lisSize * sizeof(int));
	    lis[dp[i] = pos] = sequence[i];
	}
	int ans[lisSize], i = lisSize - 1;
	for(int j = size - 1; i >= 0; --j) {
	    if(dp[j] == i)
	        ans[i--] = sequence[j];
	}
	printf("%d\n-\n", lisSize);
	for(i = 0; i < lisSize; ++i)
	    printf("%d\n", ans[i]);
	free(sequence);
	free(lis);
	return 0;
}
