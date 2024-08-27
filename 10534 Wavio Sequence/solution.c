#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(array[mid] == key)
            return mid;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        int sequence[N], *LIS = NULL, lisSize = 0, lisDP[N];
        for(int i = 0; i < N; ++i) {
            scanf("%d", &sequence[i]);
            int pos = binarySearch(LIS, lisSize, sequence[i]);
            if(pos == lisSize)
                LIS = (int*)realloc(LIS, ++lisSize * sizeof(int));
            LIS[pos] = sequence[i];
            lisDP[i] = pos + 1;
        }
        int *LDS = NULL, ldsSize = 0, ldsDP[N], max = 1;
        for(int i = N - 1; i >= 0 && max < lisSize; --i) {
            int pos = binarySearch(LDS, ldsSize, sequence[i]);
            if(pos == ldsSize)
                LDS = (int*)realloc(LDS, ++ldsSize * sizeof(int));
            LDS[pos] = sequence[i];
            ldsDP[i] = pos + 1;
            int temp = lisDP[i] < ldsDP[i] ? lisDP[i] : ldsDP[i];
            max = max > temp ? max : temp;
        }
        printf("%d\n", (max << 1) - 1);
        free(LIS);
        free(LDS);
    }
	return 0;
}
