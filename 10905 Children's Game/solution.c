#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    char *num1 = *(char**)a;
    char *num2 = *(char**)b;
    int len = strlen(num1) + strlen(num2);
    char comb1[len + 1], comb2[len + 1];
    strcpy(comb1, num1);
    strcat(comb1, num2);
    strcpy(comb2, num2);
    strcat(comb2, num1);
    return strcmp(comb2, comb1);
}

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        char **numbers = (char**)malloc(N * sizeof(char*));
        for(int i = 0; i < N; ++i) {
            numbers[i] = NULL;
            scanf("%ms", &numbers[i]);
        }
        qsort(numbers, N, sizeof(char*), compare);
        for(int i = 0; i < N; ++i) {
            fputs(numbers[i], stdout);
            free(numbers[i]);
        }
        putchar('\n');
        free(numbers);
    }
	return 0;
}
