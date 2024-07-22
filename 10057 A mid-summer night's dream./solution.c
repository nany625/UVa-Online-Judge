#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1, insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

void MergeSort(int *array, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        int reg[right - left + 1];
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = 0; i < right - left + 1; ++i) {
            if(leftPointer > mid)
                reg[i] = array[rightPointer++];
            else if(rightPointer > right)
                reg[i] = array[leftPointer++];
            else if(array[leftPointer] <= array[rightPointer])
                reg[i] = array[leftPointer++];
            else
                reg[i] = array[rightPointer++];
        }
        for(int i = 0; i < right - left + 1; ++i)
            array[i + left] = reg[i];
    }
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int X[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &X[i]);
        n <= 47 ? InsertionSort(X, n) : MergeSort(X, 0, n - 1);
        int low = (n - 1) / 2, high = n / 2;
        while(X[low] == X[low - 1])
            --low;
        while(X[high] == X[high + 1])
            ++high;
        printf("%d %d %d\n", X[(n - 1) / 2], high - low + 1, X[n / 2] - X[(n - 1) / 2] + 1);
    }
    return 0;
}
