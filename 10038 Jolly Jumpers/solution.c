#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void DualPivotQuickSort(int *array, int left, int right, bool *Jolly) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
		if(array[partitionIndices[0]] != partitionIndices[0] + 1 || array[partitionIndices[1]] != partitionIndices[1] + 1) {
		    *Jolly = false;
		    return;
		}
		DualPivotQuickSort(array, left, partitionIndices[0] - 1, Jolly);
		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1, Jolly);
		DualPivotQuickSort(array, partitionIndices[1] + 1, right, Jolly);
    }
}

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
	    int prev, curr;
	    scanf("%d", &prev);
	    int diff[--n];
	    for(int i = 0; i < n; ++i) {
	        scanf("%d", &curr);
	        diff[i] = abs(prev - curr);
	        prev = curr;
	    }
	    bool Jolly = true;
	    DualPivotQuickSort(diff, 0, n - 1, &Jolly);
	    puts(Jolly ? "Jolly": "Not jolly");
	}
	return 0;
}
