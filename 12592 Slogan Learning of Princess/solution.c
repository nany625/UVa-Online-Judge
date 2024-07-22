#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstLine[102], secondLine[102];
} Slogan;

int compare(const void *a, const void *b) {
    return strcmp(((Slogan*)a)->firstLine, ((Slogan*)b)->firstLine);
}

char *binarySearch(Slogan *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].firstLine, key);
        if(cmp == 0)
            return array[mid].secondLine;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    Slogan slogans[N];
    for(int i = 0; i < N; ++i) {
        fgets(slogans[i].firstLine, sizeof(slogans[i].firstLine), stdin);
        fgets(slogans[i].secondLine, sizeof(slogans[i].secondLine), stdin);
        slogans[i].firstLine[strcspn(slogans[i].firstLine, "\n")] = '\0';
    }
    qsort(slogans, N, sizeof(Slogan), compare);
    int Q;
    scanf("%d", &Q);
    getchar();
    while(Q--) {
        char buffer[24];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%s", binarySearch(slogans, N, buffer));
    }
    return 0;
}
