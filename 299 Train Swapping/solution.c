#include <stdio.h>

void MergeSort(int *array, int *reg, int left, int right, int *swap) {
    if(left < right) {
        int mid = left + (right - left) / 2;
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
    scanf("%d", &N);
    while(N--) {
        int L;
        scanf("%d", &L);
        int a[L], reg[L], swap = 0;
        for(int i = 0; i < L; ++i)
            scanf("%d", &a[i]);
        MergeSort(a, reg, 0, L - 1, &swap);
        printf("Optimal train swapping takes %d swaps.\n", swap);
    }
    return 0;
}
