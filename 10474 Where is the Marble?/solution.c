#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(short*)a > *(short*)b;
}

int binarySearch(short *array, int size, short key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(array[mid] == key) {
            while(mid > left && array[mid] == array[mid-1])
                --mid;
            return mid + 1;
        }
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}


int main() {
    int cases = 0, N, Q;
    while(scanf("%d %d", &N, &Q) && N != 0 && Q != 0) {
        printf("CASE# %d:\n", ++cases);
        short marbles[N];
        for(int i = 0; i < N; ++i)
            scanf("%hd", &marbles[i]);
        qsort(marbles, N, sizeof(short), compare);
        while(Q--) {
        	short query;
        	scanf("%hd", &query);
            int position = binarySearch(marbles, N, query);
            if(position != 0)
                printf("%hd found at %d\n", query, position);
            else
                printf("%hd not found\n", query);
        }
    }
    return 0;
}
