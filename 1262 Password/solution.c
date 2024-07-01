#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char firstGrid[6][6], secondGrid[6][6];

int contain(char *p, char ch) {
    int len = strlen(p);
    for(int i = 0; i < len; ++i) {
        if(p[i] == ch)
            return 1;
    }
    return 0;
}

void filter(char **p, int index) {
    *p = (char*)malloc(sizeof(char));
    (*p)[0] = '\0';
    int size = 0;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            if(firstGrid[i][index] == secondGrid[j][index]) {
                if(!contain(*p, firstGrid[i][index])) {
                    *p = (char*)realloc(*p, (size + 2) * sizeof(char));
                    (*p)[size++] = firstGrid[i][index];
                    (*p)[size] = '\0';
                }
            }
        }
    }
}

void InsertionSort(char *array) {
    int size = strlen(array);
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        char insertionChar = array[i];
        while(j >= 0 && insertionChar < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionChar;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int K;
        scanf("%d", &K);
        for(int i = 0; i < 6; ++i)
            scanf("%s", firstGrid[i]);
        for(int i = 0; i < 6; ++i)
            scanf("%s", secondGrid[i]);
        char *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
        filter(&p1, 0);
        filter(&p2, 1);
        filter(&p3, 2);
        filter(&p4, 3);
        filter(&p5, 4);
        int len1 = strlen(p1);
        int len2 = strlen(p2);
        int len3 = strlen(p3);
        int len4 = strlen(p4);
        int len5 = strlen(p5);
        if(len1 * len2 * len3 * len4 * len5 < K)
            puts("NO");
        else {
            InsertionSort(p1);
            InsertionSort(p2);
            InsertionSort(p3);
            InsertionSort(p4);
            InsertionSort(p5);
            putchar(p1[--K / len2 / len3 / len4 / len5]);
            K %= len2 * len3 * len4 * len5;
            putchar(p2[K / len3 / len4 / len5]);
            K %= len3 * len4 * len5;
            putchar(p3[K / len4 / len5]);
            K %= len4 * len5;
            putchar(p4[K / len5]);
            putchar(p5[K % len5]);
            puts("");
        }
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
    }
    return 0;
}
