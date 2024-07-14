#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int binarySearch(int *array, int size, double key) {
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
        int l, n;
        scanf("%d %d", &l, &n);
        int pos[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &pos[i]);
        qsort(pos, n, sizeof(int), compare);
        int temp = binarySearch(pos, n, l / 2.0);
        int min = pos[temp - 1] > l - pos[temp] ? pos[temp - 1] : l - pos[temp];
        int max = l - pos[0] > pos[n - 1] ? l - pos[0] : pos[n - 1];
        printf("%d %d\n", min, max);
    }
    return 0;
}
