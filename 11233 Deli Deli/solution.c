#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *singular, *plural;
} Word;

int compare(const void *a, const void *b) {
    return strcmp(((Word*)a)->singular, ((Word*)b)->singular);
}

int binarySearch(Word *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].singular, key);
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
    int L, N;
    scanf("%d %d", &L, &N);
    Word irregular[L];
    for(int i = 0; i < L; ++i)
        scanf("%ms %ms", &irregular[i].singular, &irregular[i].plural);
    qsort(irregular, L, sizeof(Word), compare);
    char word[21];
    while(N--) {
        scanf("%s", word);
        int pos = binarySearch(irregular, L, word);
        if(pos != -1)
            printf("%s\n", irregular[pos].plural);
        else {
            int len = strlen(word);
            if(word[len - 1] == 'y') {
                if(word[len - 2] == 'a' || word[len - 2] == 'e' || word[len - 2] == 'i' || word[len - 2] == 'o' || word[len - 2] == 'u')
                    printf("%ss\n", word);
                else
                    printf("%.*sies\n", len - 1, word);
            } else if(word[len - 1] == 'o' || word[len - 1] == 's' || strncmp(word + len - 2, "ch", 2) == 0 || strncmp(word + len - 2, "sh", 2) == 0 || word[len - 1] == 'x')
                printf("%ses\n", word);
            else
                printf("%ss\n", word);
        }
    }
    for(int i = 0; i < L; ++i) {
        free(irregular[i].singular);
        free(irregular[i].plural);
    }
    return 0;
}
