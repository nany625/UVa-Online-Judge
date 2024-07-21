#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &x) == 1) {
        getchar();
        getline(&buffer, &bufsize, stdin);
        long *a = NULL;
        int size = 0;
        char *token = strtok(buffer, " ");
        while(token) {
            a = (long*)realloc(a, (size + 1) * sizeof(long));
            a[size++] = atol(token);
            token = strtok(NULL, " ");
        }
        --size;
        long result = 0;
        for(int i = 0; i < size; ++i)
            result = result * x + a[i] * (size - i);
        printf("%ld\n", result);
        free(a);
    }
    free(buffer);
    return 0;
}
