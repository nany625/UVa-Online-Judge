#include <stdio.h>
#include <stdlib.h>

int *C, size;

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int binarySearch(int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(C[mid] == key)
            return mid;
        if(C[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    long i = 1;
    while(i <= 2147483647) {
        long temp = i;
        do {
            C = (int*)realloc(C, (size + 1) * sizeof(int));
            C[size++] = temp;
            temp *= 3;
        } while(temp <= 2147483647);
        i <<= 1;
    }
    qsort(C, size, sizeof(int), compare);
    int m;
    while(scanf("%d", &m) && m != 0) {
        int pos = binarySearch(m);
        printf("%ld\n", pos < size ? C[pos] : 2147483648);
    }
    free(C);
	return 0;
}
