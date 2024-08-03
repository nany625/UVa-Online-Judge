// #解法一
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
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
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int n;
        scanf("%d", &n);
        int weights[2 * n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &weights[n + i]);
            weights[n - 1 - i] = weights[n + i];
        }
        int *lis = NULL, size = 0;
        for(int i = 2 * n - 1; i >= 0; --i) {
            int pos = binarySearch(lis, size, weights[i]);
            if(pos == size)
                lis = (int*)realloc(lis, ++size * sizeof(int));
            lis[pos] = weights[i];
        }
        printf("%d\n", size);
        free(lis);
    }
	return 0;
}

// #解法二
#include <stdio.h>
#include <stdlib.h>

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int n;
        scanf("%d", &n);
        int weights[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &weights[i]);
        int *lis = NULL, lisSize = 0;
        int *lds = NULL, ldsSize = 0, max = 0;
        for(int i = n - 1; i >= 0; --i) {
            int left = 0, right = lisSize - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(lis[mid] < weights[i])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            if(left == lisSize)
                lis = (int*)realloc(lis, ++lisSize * sizeof(int));
            lis[left] = weights[i];
            int temp = left + 1;
            left = 0, right = ldsSize - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(lds[mid] > weights[i])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            if(left == ldsSize)
                lds = (int*)realloc(lds, ++ldsSize * sizeof(int));
            lds[left] = weights[i];
            temp += left;
            max = max > temp ? max : temp;
        }
        printf("%d\n", max);
        free(lis);
        free(lds);
    }
	return 0;
}
