#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DualPivotPartition(int *array, int *partitionIndices, int left, int right) {
    if(array[left] < array[right])
        swap(&array[left], &array[right]);
    int low = left + 1, high = right - 1, pivot1 = array[left], pivot2 = array[right];
    for(int i = low; i <= high; ++i) {
        if(array[i] > pivot1)
            swap(&array[low++], &array[i]);
        else if(array[i] < pivot2)
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

int main() {
    int t;
    scanf("%d", &t);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(t--) {
        int n;
        scanf("%d", &n);
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int p[n];
        for(int i = 0; i < n; ++i) {
            p[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        DualPivotQuickSort(p, 0, n - 1);
        int save = 0;
        for(int i = 2; i < n; i += 3)
            save += p[i];
        printf("%d\n", save);
    }
    free(buffer);
    return 0;
}
