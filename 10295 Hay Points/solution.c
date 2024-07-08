#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word = NULL;
    int value;
} Dictionary;

int compare(const void *a, const void *b) {
    Dictionary *d1 = (Dictionary*)a;
    Dictionary *d2 = (Dictionary*)b;
    return strcmp(d1->word, d2->word);
}

int binarySearch(Dictionary *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].word, key);
        if(cmp == 0)
            return array[mid].value;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    Dictionary dict[m];
    for(int i = 0; i < m; ++i)
        scanf("%ms %d", &dict[i].word, &dict[i].value);
    qsort(dict, m, sizeof(Dictionary), compare);
    while(n--) {
        int salary = 0;
        char *word = NULL;
        while(scanf("%ms", &word) && strcmp(word, ".") != 0) {
            salary += binarySearch(dict, m, word);
            free(word);
        }
        free(word);
        printf("%d\n", salary);
    }
    for(int i = 0; i < m; ++i)
        free(dict[i].word);
    return 0;
}
