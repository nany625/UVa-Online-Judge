#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(array[mid] == key)
            return mid;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void insert(int **set, int *sizeSet, int pos, int value) {
    if(!(pos < *sizeSet && (*set)[pos] == value)) {
        *set = (int*)realloc(*set, (*sizeSet + 1) * sizeof(int));
    	for(int i = (*sizeSet)++; i > pos; --i)
    	    (*set)[i] = (*set)[i - 1];
    	(*set)[pos] = value;
    }
}

void appendSet(int **set, int **uni, int *sizeSet, int *sizeUni, char *buffer) {
    char *token = strtok(buffer, " ");
    while(token) {
        int value = atoi(token), pos = binarySearch(*set, *sizeSet, value);
	    insert(set, sizeSet, pos, value);
	    pos = binarySearch(*uni, *sizeUni, atoi(token));
	    insert(uni, sizeUni, pos, value);
	    token = strtok(NULL, " ");
	}
}

int main() {
	char *bufferA = NULL, *bufferB = NULL;
	size_t bufsizea = 0, bufsizeb = 0;
	while(getline(&bufferA, &bufsizea, stdin) != -1 && getline(&bufferB, &bufsizeb, stdin)) {
	    int *setA = NULL, *setB = NULL, *uni = NULL;
	    int sizeA = 0, sizeB = 0, sizeUni = 0;
	    appendSet(&setA, &uni, &sizeA, &sizeUni, bufferA);
	    appendSet(&setB, &uni, &sizeB, &sizeUni, bufferB);
	    if(sizeUni == sizeA && sizeUni == sizeB)
	        puts("A equals B");
	    else if(sizeUni == sizeA && sizeUni != sizeB)
	        puts("B is a proper subset of A");
	    else if(sizeUni == sizeB && sizeUni != sizeA)
	        puts("A is a proper subset of B");
	    else if(sizeUni == sizeA + sizeB)
	        puts("A and B are disjoint");
	    else
	        puts("I'm confused!");
	    free(setA);
	    free(setB);
	    free(uni);
	}
	free(bufferA);
	free(bufferB);
	return 0;
}
