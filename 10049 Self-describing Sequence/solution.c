#include <stdio.h>
#include <stdlib.h>

int *f = NULL, size;

int binarySearch(int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(f[mid] == key)
            return mid + 1;
        if(f[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
	f = (int*)malloc(sizeof(int));
	f[0] = size = 1;
	while(f[size - 1] <= 2000000000) {
	    int pos = binarySearch(size);
	    f = (int*)realloc(f, (size + 1) * sizeof(int));
	    f[size] = f[size - 1] + pos;
	    ++size;
	}
	int n;
	while(scanf("%d", &n) && n != 0)
	    printf("%d\n", binarySearch(n));
	free(f);
	return 0;
}
