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
            }
            else if(rightPointer > right)
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

int binarySearch(short *array, int size, short key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid] == key) {
            while(mid < size && array[mid] == array[mid + 1])
                ++mid;
            return mid + 1;
        }
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		short A[n - 1];
		int sum = 0;
		for(int i = 0; i < n - 1; ++i) {
		    short temp;
		    scanf("%hd", &temp);
		    int pos = binarySearch(A, i, temp);
		    sum += pos;
		    for(int j = i; j > pos; --j)
		        A[j] = A[j - 1];
		    A[pos] = temp;
		}
		int temp;
		scanf("%d", &temp);
		printf("%d\n", sum + binarySearch(A, n - 1, temp));
	}
	return 0;
}

// #解法三
#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int A[n], sum = 0;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &A[j]);
			for(int k = 0; k < j; ++k) {
				if(A[k] <= A[j])
					++sum;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
