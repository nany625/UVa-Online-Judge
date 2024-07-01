#include <stdio.h>

void swap(short *a, short *b) {
	short temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotPartition(short *array, int *partitionIndices, int left, int right) {
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

void DualPivotQuickSelect(short *array, int left, int right, int median) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
        if(median == partitionIndices[0] || median == partitionIndices[1])
            return;
        if(median < partitionIndices[0])
		    DualPivotQuickSelect(array, left, partitionIndices[0] - 1, median);
		else if(median > partitionIndices[1])
		    DualPivotQuickSelect(array, partitionIndices[1] + 1, right, median);
		else
		    DualPivotQuickSelect(array, partitionIndices[0] + 1, partitionIndices[1] - 1, median);
    }
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int S, A, F;
		scanf("%d %d %d", &S, &A, &F);
		short streetLocations[F], avenueLocations[F];
		for(int i = 0; i < F; ++i)
			scanf("%hd %hd", &streetLocations[i], &avenueLocations[i]);
		int median = (F - 1) / 2;
		DualPivotQuickSelect(streetLocations, 0, F - 1, median);
		DualPivotQuickSelect(avenueLocations, 0, F - 1, median);
		printf("(Street: %hd, Avenue: %hd)\n", streetLocations[median], avenueLocations[median]);
	}
	return 0;
}
