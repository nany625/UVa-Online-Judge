#include <stdio.h>
#include <stdlib.h>

short *lenMap = NULL;

void Collatz(int n) {
    if(n % 2 == 0) {
        lenMap[n] = lenMap[n / 2] + 1;
        return;
    }
    lenMap[n] = 1;
    long temp = n;
    while(temp != 1) {
        if(temp < n) {
            lenMap[n] += lenMap[temp] - 1;
            return;
        }
        temp = temp % 2 == 1 ? 3 * temp + 1 : temp / 2;
        ++lenMap[n];
    }
}

int main() {
    lenMap = (short*)malloc(2 * sizeof(short));
    lenMap[0] = 0;
    lenMap[1] = 1;
    int min, max, size = 2;
    while(scanf("%d %d", &min, &max) == 2) {
    	printf("%d %d ", min, max);
    	if(min > max) {
    	    int temp = min;
    	    min = max;
    	    max = temp;
    	}
    	for(int i = size; i <= min; ++i) {
    	    lenMap = (short*)realloc(lenMap, (size++ + 1) * sizeof(short));
    	    Collatz(i);
    	}
    	short maxLen = lenMap[min];
        for(int i = min + 1; i <= max; ++i) {
            if(i >= size) {
                lenMap = (short*)realloc(lenMap, (size++ + 1) * sizeof(short));
                Collatz(i);
            }
            maxLen = maxLen > lenMap[i] ? maxLen : lenMap[i];
        }
        printf("%d\n", maxLen);
    }
    free(lenMap);
    return 0;
}
