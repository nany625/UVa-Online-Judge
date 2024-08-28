#include <stdio.h>

void MergeSort(int *array, int *reg, int left, int right) {
    if(left < right) {
        int mid = left + ((right - left) >> 1);
        MergeSort(array, reg, left, mid);
        MergeSort(array, reg, mid + 1, right);
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = left; i <= right; ++i) {
            if(leftPointer > mid)
                reg[i] = array[rightPointer++];
            else if(rightPointer > right)
                reg[i] = array[leftPointer++];
            else if(array[leftPointer] <= array[rightPointer])
                reg[i] = array[leftPointer++];
            else
                reg[i] = array[rightPointer++];
        }
        for(int i = left; i <= right; ++i)
            array[i] = reg[i];
    }
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int X[n], reg[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &X[i]);
        MergeSort(X, reg, 0, n - 1);
        int low = (n - 1) >> 1, high = n >> 1;
        while(low > 0 && X[low] == X[low - 1])
            --low;
        while(high < n - 1 && X[high] == X[high + 1])
            ++high;
        printf("%d %d %d\n", X[(n - 1) >> 1], high - low + 1, X[n >> 1] - X[(n - 1) >> 1] + 1);
    }
    return 0;
}
