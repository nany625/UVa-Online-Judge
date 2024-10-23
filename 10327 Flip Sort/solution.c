#include <stdio.h>

void MergeSort(int *array, int *reg, int left, int right, int *swap) {
    if(left < right) {
        int mid = left + (right - left >> 1);
        MergeSort(array, reg, left, mid, swap);
        MergeSort(array, reg, mid + 1, right, swap);
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = left; i <= right; ++i) {
            if(leftPointer > mid) {
                reg[i] = array[rightPointer++];
                *swap += mid - leftPointer + 1;
            } else if(rightPointer > right)
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
    int N;
    while(scanf("%d", &N) == 1) {
        int array[N], reg[N], swap = 0;
        for(int i = 0; i < N; ++i)
            scanf("%d", &array[i]);
        MergeSort(array, reg, 0, N - 1, &swap);
        printf("Minimum exchange operations : %d\n", swap);
    }
    return 0;
}
