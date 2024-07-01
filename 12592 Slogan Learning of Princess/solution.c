#include <stdio.h>
#include <string.h>

typedef struct {
    char firstLine[102], secondLine[102];
} Slogan;

void InsertionSort(Slogan *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        Slogan temp = array[i];
        while(j >= 0 && strcmp(temp.firstLine, array[j].firstLine) < 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
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
        slogans[i].secondLine[strcspn(slogans[i].secondLine, "\n")] = '\0';
    }
    InsertionSort(slogans, N);
    int Q;
    scanf("%d", &Q);
    getchar();
    while(Q--) {
        char hear[102];
        fgets(hear, sizeof(hear), stdin);
        hear[strcspn(hear, "\n")] = '\0';
        printf("%s\n", binarySearch(slogans, N, hear));
    }
    return 0;
}
