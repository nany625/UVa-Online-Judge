// #解法一
#include <stdio.h>

void MergeSort(short *array, short *reg, int left, int right, int *sum) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(array, reg, left, mid, sum);
        MergeSort(array, reg, mid + 1, right, sum);
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = left; i <= right; ++i) {
            if(leftPointer > mid) {
                reg[i] = array[rightPointer++];
                *sum += leftPointer - left;
            } else if(rightPointer > right)
                reg[i] = array[leftPointer++];
            else if(array[leftPointer] <= array[rightPointer])
                reg[i] = array[leftPointer++];
            else {
                reg[i] = array[rightPointer++];
                *sum += leftPointer - left;
            }
        }
        for(int i = left; i <= right; ++i)
            array[i] = reg[i];
    }
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		short A[n], reg[n];
		for(int i = 0; i < n; ++i)
		    scanf("%hd", &A[i]);
		int sum = 0;
		MergeSort(A, reg, 0, n - 1, &sum);
		printf("%d\n", sum);
	}
	return 0;
}

// #解法二
#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		short A[n];
        int sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%hd", &A[i]);
			for(int j = 0; j < i; ++j)
				sum += A[j] <= A[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
