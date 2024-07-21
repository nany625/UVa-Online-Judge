#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char english[11], foreign[11];
} Dictionary;

int compare(const void *a, const void *b) {
    return strcmp(((Dictionary*)a)->foreign, ((Dictionary*)b)->foreign);
}

const char *binarySearch(Dictionary *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].foreign, key);
        if(cmp == 0)
            return array[mid].english;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return "eh";
}

int main() {
    Dictionary *dict = NULL;
    int size = 0;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1 && strcmp(buffer, "\n") != 0) {
        buffer[strcspn(buffer, "\n")] = '\0';
        dict = (Dictionary*)realloc(dict, (size + 1) * sizeof(Dictionary));
        char *token = strtok(buffer, " ");
        strcpy(dict[size].english, token);
        token = strtok(NULL, " ");
        strcpy(dict[size++].foreign, token);
    }
    qsort(dict, size, sizeof(Dictionary), compare);
    while(scanf("%s", buffer) == 1)
        printf("%s\n", binarySearch(dict, size, buffer));
    free(buffer);
    return 0;
}
