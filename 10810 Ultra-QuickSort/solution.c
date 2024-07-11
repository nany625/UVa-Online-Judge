#include <stdio.h>

void MergeSort(int *array, int *reg, int left, int right, long *swap) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(array, reg, left, mid, swap);
        MergeSort(array, reg, mid + 1, right, swap);
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = left; i <= right; ++i) {
            if(leftPointer > mid) {
                reg[i] = array[rightPointer++];
                *swap += mid - leftPointer + 1;
            }
            else if(rightPointer > right)
                reg[i] = array[leftPointer++];
            else if(array[leftPointer] <= array[rightPointer])
                reg[i] = array[leftPointer++];
            else {
                reg[i] = array[rightPointer++];
                *swap += mid - leftPointer + 1;
            }
        }
        for(int i = left; i <= right; ++i)
            array[i] = reg[i];
    }
}

int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
	    int array[n], reg[n];
	    long swap = 0;
	    for(int i = 0; i < n; ++i)
	        scanf("%d", &array[i]);
	    MergeSort(array, reg, 0, n - 1, &swap);
	    printf("%ld\n", swap);
	}
	return 0;
}
