// #解法一
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long froshes;
    short popularity;
} Combination;

void InsertionSort(short *array) {
    for(int i = 1; i < 5; ++i) {
        int j = i - 1;
        short insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

int binarySearch(Combination *array, short size, long key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid].froshes == key)
            return mid;
        if(array[mid].froshes < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    short courses[5];
	int n;
	while(scanf("%d", &n) && n != 0) {
	    Combination *combinations = NULL;
		short size = 0, max = 0, students = 0;
		while(n--) {
		    for(int i = 0; i < 5; ++i)
		        scanf("%hd", &courses[i]);
		    InsertionSort(courses);
		    long temp = 0;
		    for(int i = 0; i < 5; ++i)
		        temp += 1000 * temp + courses[i];
		    int pos = binarySearch(combinations, size, temp);
		    if(pos < size && combinations[pos].froshes == temp) {
		        ++combinations[pos].popularity;
		        if(max < combinations[pos].popularity)
				    students = max = combinations[pos].popularity;
				else if(max == combinations[pos].popularity)
				    students += max;
		    } else {
		        combinations = (Combination*)realloc(combinations, (size + 1) * sizeof(Combination));
		        for(int i = size++; i > pos; --i)
                    combinations[i] = combinations[i - 1];
                combinations[pos].froshes = temp;
                combinations[pos].popularity = 1;
		        if(max < 1)
				    students = max = 1;
				else if(max == 1)
					++students;
		    }
		}
		printf("%hd\n", students);
		free(combinations);
	}
	return 0;
}

// #解法二(by ChatGPT 我暫時不會寫)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HASH_SIZE 100003

typedef struct Combination {
    long froshes;
    short popularity;
    struct Combination *next;
} Combination;

unsigned long hash(long key) {
    return (unsigned long)key % HASH_SIZE;
}

void addCombination(Combination **hashTable, long key, short *max, int *students) {
    unsigned long index = hash(key);
    Combination *entry = hashTable[index];

    while (entry != NULL) {
        if (entry->froshes == key) {
            entry->popularity++;
            if (entry->popularity > *max) {
                *max = entry->popularity;
                *students = *max;
            } else if (entry->popularity == *max) {
                *students += *max;
            }
            return;
        }
        entry = entry->next;
    }

    entry = (Combination *)malloc(sizeof(Combination));
    if (entry == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    entry->froshes = key;
    entry->popularity = 1;
    entry->next = hashTable[index];
    hashTable[index] = entry;

    if (*max == 1) {
        (*students)++;
    } else if (*max == 0) {
        *max = 1;
        *students = 1;
    }
}

void InsertionSort(short *array) {
    for(int i = 1; i < 5; ++i) {
        int j = i - 1;
        short insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

int main() {
    short courses[5];
	int n;
	while(scanf("%d", &n) && n != 0) {
	    Combination *hashTable[HASH_SIZE] = {0};
        short max = 0;
        int students = 0;
		while(n--) {
		    for(int i = 0; i < 5; ++i)
		        scanf("%hd", &courses[i]);
		    InsertionSort(courses);
		    long temp = 0;
		    for(int i = 0; i < 5; ++i)
		        temp += 1000 * temp + courses[i];
		    addCombination(hashTable, temp, &max, &students);
		}
		printf("%hd\n", students);
		for (int i = 0; i < HASH_SIZE; i++) {
            Combination *entry = hashTable[i];
            while (entry != NULL) {
                Combination *prev = entry;
                entry = entry->next;
                free(prev);
            }
        }
	}
	return 0;
}
