#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x;
    while(scanf("%d", &x) == 1) {
        getchar();
        char *buffer = NULL;
        size_t bufsize = 0;
        getline(&buffer, &bufsize, stdin);
        long *a = NULL;
        int size = 0;
        char *token = strtok(buffer, " ");
        while(token) {
            a = (long*)realloc(a, (size + 1) * sizeof(long));
            a[size++] = atol(token);
            token = strtok(NULL, " ");
        }
        free(buffer);
        --size;
        long result = 0;
        for(int i = 0; i < size; ++i)
            result = result * x + a[i] * (size - i);
        printf("%ld\n", result);
        free(a);
    }
    return 0;
}
