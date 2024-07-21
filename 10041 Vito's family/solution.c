#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void DualPivotQuickSelect(int *array, int left, int right, int median) {
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
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
	size_t bufsize = 0;
    while(cases--) {
        int r;
        scanf("%d", &r);
        int s[r];
        getline(&buffer, &bufsize, stdin);
	    char *token = strtok(buffer, " ");
        for(int i = 0; i < r; ++i) {
            s[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        int median = (r - 1) / 2;
        DualPivotQuickSelect(s, 0, r - 1, median);
        long d = 0;
        for(int i = 0; i < r; ++i)
            d += abs(s[median] - s[i]);
        printf("%ld\n", d);
    }
    free(buffer);
    return 0;
}
