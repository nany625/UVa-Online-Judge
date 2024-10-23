#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[17];
    int value;
} Dictionary;

int compare(const void *a, const void *b) {
    return strcmp(((Dictionary*)a)->word, ((Dictionary*)b)->word);
}

int binarySearch(Dictionary *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
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
        scanf("%s %d", dict[i].word, &dict[i].value);
    qsort(dict, m, sizeof(Dictionary), compare);
    char word[17];
    while(n--) {
        int salary = 0;
        while(scanf("%s", word) && word[0] != '.')
            salary += binarySearch(dict, m, word);
        printf("%d\n", salary);
    }
    return 0;
}
