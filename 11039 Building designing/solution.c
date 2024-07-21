#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotPartition(int *array, int *partitionIndices, int left, int right) {
	if(array[left] > array[right])
		swap(&array[left], &array[right]);
	int low = left + 1, high = right - 1, pivot1 = array[left], pivot2 = array[right];
	for(int i = low; i <= high; ++i) {
		if(array[i] < pivot1)
			swap(&array[low++], &array[i]);
		else if(array[i] > pivot2)
			swap(&array[high--], &array[i--]);
	}
	swap(&array[--low], &array[left]);
	swap(&array[++high], &array[right]);
	partitionIndices[0] = low;
	partitionIndices[1] = high;
}

void DualPivotQuickSort(int *array, int left, int right) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
		DualPivotQuickSort(array, left, partitionIndices[0] - 1);
		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1);
		DualPivotQuickSort(array, partitionIndices[1] + 1, right);
    }
}

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(left > 0 && array[left - 1] + array[left] > 0)
	    --left;
    return left;
}

int main() {
	int p;
	scanf("%d", &p);
	while(p--) {
	    int floors;
	    scanf("%d", &floors);
	    int size[floors];
	    for(int i = 0; i < floors; ++i)
	        scanf("%d", &size[i]);
	    DualPivotQuickSort(size, 0, floors - 1);
	    int leftPointer = binarySearch(size, floors, 0), rightPointer = leftPointer, above = size[leftPointer], count = floors > 0;
	    while(leftPointer >= 0 && rightPointer < floors) {
	        if(above > 0) {
	            do {
	                --leftPointer;
	            } while(leftPointer >= 0 && size[leftPointer] + above > 0);
	            if(leftPointer >= 0) {
	                ++count;
	                above = size[leftPointer];
	            }
	        } else {
	            do {
	                ++rightPointer;
	            } while(rightPointer < floors && size[rightPointer] + above < 0);
	            if(rightPointer < floors) {
	                ++count;
	                above = size[rightPointer];
	            }
	        }
	    }
	    printf("%d\n", count);
	}
	return 0;
}
