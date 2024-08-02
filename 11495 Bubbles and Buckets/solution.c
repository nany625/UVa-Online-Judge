#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeSort(int *array, int *reg, int left, int right, long *swap) {
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
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &N) && N != 0) {
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int P[N], reg[N];
        for(int i = 0; i < N; ++i) {
            P[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        long swap = 0;
        MergeSort(P, reg, 0, N - 1, &swap);
        puts(swap % 2 == 1 ? "Marcelo" : "Carlos");
    }
    free(buffer);
	return 0;
}
