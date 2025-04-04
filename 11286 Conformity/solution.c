// #解法一
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long froshes;
    short popularity;
} Combination;

short courses[5];

void InsertionSort() {
    for(int i = 1; i < 5; ++i) {
        int j = i - 1;
        short insertionNum = courses[i];
        while(j >= 0 && insertionNum < courses[j]) {
            courses[j + 1] = courses[j];
            --j;
        }
        courses[j + 1] = insertionNum;
    }
}

int binarySearch(Combination *array, short size, long key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
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
	int n;
	while(scanf("%d", &n) && n != 0) {
	    Combination *combinations = NULL;
		short size = 0;
		while(n--) {
		    for(int i = 0; i < 5; ++i)
		        scanf("%hd", &courses[i]);
		    InsertionSort();
		    long temp = 0;
		    for(int i = 0; i < 5; ++i)
		        temp += 1000 * temp + courses[i];
		    int pos = binarySearch(combinations, size, temp);
		    if(pos < size && combinations[pos].froshes == temp)
		        ++combinations[pos].popularity;
		    else {
		        combinations = (Combination*)realloc(combinations, (size + 1) * sizeof(Combination));
		        for(int i = size++; i > pos; --i)
                    combinations[i] = combinations[i - 1];
                combinations[pos] = (Combination){temp, 1};
		    }
		}
		short max = 0, students = 0;
		for(int i = 0; i < size; ++i) {
		    if(max < combinations[i].popularity)
		        students = max = combinations[i].popularity;
		    else if(max == combinations[i].popularity)
		        students += max;
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

void addCombination(Combination **hashTable, long key) {
    unsigned long index = hash(key);
    Combination *entry = hashTable[index];

    while (entry != NULL) {
        if (entry->froshes == key) {
            entry->popularity++;
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
}

void InsertionSort(short *array) {
    for (int i = 1; i < 5; ++i) {
        int j = i - 1;
        short insertionNum = array[i];
        while (j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

int main() {
    short courses[5];
    int n;

    while (scanf("%d", &n) && n != 0) {
        Combination *hashTable[HASH_SIZE] = {0};

        while (n--) {
            for (int i = 0; i < 5; ++i)
                scanf("%hd", &courses[i]);
            InsertionSort(courses);

            long temp = 0;
            for (int i = 0; i < 5; ++i)
                temp = 1000 * temp + courses[i];

            addCombination(hashTable, temp);
        }

        // 計算 max 和 students
        short max = 0;
        int students = 0;
        for (int i = 0; i < HASH_SIZE; i++) {
            Combination *entry = hashTable[i];
            while (entry != NULL) {
                if (entry->popularity > max) {
                    students = max = entry->popularity;
                } else if (entry->popularity == max) {
                    students += max;
                }
                entry = entry->next;
            }
        }

        printf("%hd\n", students);

        // 釋放記憶體
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
