#include <stdio.h>
#include <stdlib.h>

void swap(short *a, short *b) {
    short temp = *a;
    *a = *b;
    *b = temp;
}

void DualPivotPartition(short *array, int *partitionIndices, int left, int right) {
    if(array[left] > array[right])
        swap(&array[left], &array[right]);
    int low = left + 1, high = right - 1;
    short pivot1 = array[left], pivot2 = array[right];
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
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int r;
        scanf("%d", &r);
        short s[r];
        for(int i = 0; i < r; ++i)
            scanf("%hd", &s[i]);
        int median = (r - 1) / 2;
        DualPivotQuickSelect(s, 0, r - 1, median);
        long d = 0;
        for(int i = 0; i < r; ++i)
            d += abs(s[median] - s[i]);
        printf("%ld\n", d);
    }
    return 0;
}
