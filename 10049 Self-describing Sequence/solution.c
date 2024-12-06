#include <stdio.h>
#include <stdlib.h>

int *f, size;

int binarySearch(int key) {
    int left = 0, right = size - 2;
    while(left <= right) {
        int mid = left + (right - left >> 1);
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
	int pos = 0;
	while(f[size - 1] <= 2000000000) {
	    f = (int*)realloc(f, (size + 1) * sizeof(int));
	    f[size] = f[size - 1] + (pos += size >= f[pos]);
	    ++size;
	}
	int n;
	while(scanf("%d", &n) && n != 0)
	    printf("%d\n", binarySearch(n));
	free(f);
	return 0;
}
