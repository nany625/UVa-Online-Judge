#include <stdio.h>
#include <math.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(double *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        double insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

void DualPivotPartition(double *array, int *partitionIndices, int left, int right) {
    if(array[left] > array[right])
        swap(&array[left], &array[right]);
    int low = left + 1, high = right - 1;
    double pivot1 = array[left], pivot2 = array[right];
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

void DualPivotQuickSort(double *array, int left, int right) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
        DualPivotQuickSort(array, left, partitionIndices[0] - 1);
        DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1);
        DualPivotQuickSort(array, partitionIndices[1] + 1, right);
    }
}

int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
        double expense[n];
	    int total = 0;
	    for(int i = 0; i < n; ++i) {
	        scanf("%lf", &expense[i]);
	        expense[i] = round(expense[i] * 100);
	        total += expense[i];
	    }
	    n <= 47 ? InsertionSort(expense, n) : DualPivotQuickSort(expense, 0, n - 1);
	    int overpayCount = total % n, average = total / n, exchange[2] = {};
	    for(int i = 0; i < n - overpayCount; ++i) {
	        if(expense[i] < average)
	            exchange[0] += average - expense[i];
	        else
	            exchange[1] += expense[i] - average;
	    }
	    for(int i = n - overpayCount; i < n; ++i) {
	        if(expense[i] < average + 1)
	            exchange[0] += (average + 1) - expense[i];
	        else
	            exchange[1] += expense[i] - (average + 1);
	    }
	    printf("$%.2f\n", exchange[0] < exchange[1] ? exchange[0] / 100.0 : exchange[1] / 100.0);
	}
	return 0;
}
