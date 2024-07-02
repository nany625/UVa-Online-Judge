#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(char *array) {
    int size = strlen(array);
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        char insertionChar = array[i];
        while(j >= 0 && insertionChar > array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionChar;
    }
}

bool contain(int *array, int size, int key) {
    for(int i = 0; i < size; ++i) {
        if(array[i] == key)
            return true;
    }
    return false;
}

int main() {
	char number[10];
	while(scanf("%s", number) && strcmp(number, "0") != 0) {
		printf("Original number was %s\n", number);
		int *numbers = NULL, size = 0;
		do {
		    numbers = (int*)realloc(numbers, (size + 1) * sizeof(int));
		    numbers[size++] = atoi(number);
		    InsertionSort(number);
    		int desc = atoi(number), len = strlen(number);
    		for(int i = 0; i < len / 2; ++i)
    		    swap(&number[i], &number[len - 1 - i]);
    		int asc = atoi(number);
    		printf("%d - %d = %d\n", desc, asc, desc - asc);
    		sprintf(number, "%d", desc - asc);
		} while(!contain(numbers, size, atoi(number)));
		printf("Chain length %d\n\n", size);
		free(numbers);
	}
	return 0;
}
