#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int value;
} Dictionary;

void swap(Dictionary *a, Dictionary *b) {
	Dictionary temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(Dictionary *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        Dictionary temp = array[i];
        while(j >= 0 && strcmp(temp.word, array[j].word) < 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
}

void DualPivotPartition(Dictionary *array, int *partitionIndices, int left, int right) {
	if(strcmp(array[left].word, array[right].word) > 0)
		swap(&array[left], &array[right]);
	int low = left + 1, high = right - 1;
	Dictionary pivot1 = array[left], pivot2 = array[right];
	for(int i = low; i <= high; ++i) {
		if(strcmp(array[i].word, pivot1.word) < 0)
			swap(&array[low++], &array[i]);
		else if(strcmp(array[i].word, pivot2.word) > 0)
			swap(&array[high--], &array[i--]);
	}
	swap(&array[--low], &array[left]);
	swap(&array[++high], &array[right]);
	partitionIndices[0] = low;
	partitionIndices[1] = high;
}

void DualPivotQuickSort(Dictionary *array, int left, int right) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
		DualPivotQuickSort(array, left, partitionIndices[0] - 1);
		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1);
		DualPivotQuickSort(array, partitionIndices[1] + 1, right);
    }
}

int binarySearch(Dictionary *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].word, key);
        if(cmp == 0)
            return mid;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    Dictionary dict[m];
    char word[17];
    for(int i = 0; i < m; ++i) {
        scanf("%s %d", word, &dict[i].value);
        dict[i].word = (char*)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(dict[i].word, word);
    }
    m <= 47 ? InsertionSort(dict, m) : DualPivotQuickSort(dict, 0, m - 1);
    while(n--) {
        int salary = 0;
        while(scanf("%s", word) && strcmp(word, ".") != 0) {
            int pos = binarySearch(dict, m, word);
            if(pos != -1)
                salary += dict[pos].value;
        }
        printf("%d\n", salary);
    }
    for(int i = 0; i < m; ++i)
        free(dict[i].word);
    return 0;
}
