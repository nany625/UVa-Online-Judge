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
		short temp;
		scanf("%hd", &temp);
		sum += binarySearch(A, n - 1, temp);
		printf("%d\n", sum);
	}
	return 0;
}
