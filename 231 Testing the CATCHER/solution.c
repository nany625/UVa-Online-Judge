#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearch(short *array, int size, short key) {
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
    int cases = 0;
	short n;
	bool firstCase = true;
	while(scanf("%hd", &n) && n != -1) {
	    if(!firstCase)
	        putchar('\n');
	    short *heights = (short*)malloc(sizeof(short));
	    heights[0] = n;
	    int size = 1;
	    while(scanf("%hd", &n) && n != -1) {
	        heights = (short*)realloc(heights, (size + 1) * sizeof(short));
	        heights[size++] = n;
	    }
	    short *lis = NULL;
	    int lisSize = 0;
	    for(int i = size - 1; i >= 0; --i) {
	        int pos = binarySearch(lis, lisSize, heights[i]);
	        if(pos == lisSize)
	            lis = (short*)realloc(lis, ++lisSize * sizeof(short));
	        lis[pos] = heights[i];
	    }
	    printf("Test #%d:\n  maximum possible interceptions: %d\n", ++cases, lisSize);
	    free(heights);
	    free(lis);
	    firstCase = false;
	}
	return 0;
}
