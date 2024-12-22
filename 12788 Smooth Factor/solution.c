#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d ", &n) == 1) {
        int a[n];
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        for(int i = 0; i < n; ++i) {
            a[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        int *indices = NULL, size = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i - 1] > a[i]) {
                indices = (int*)realloc(indices, (size + 1) * sizeof(int));
                indices[size++] = i;
            }
        }
        if(size <= 1)
            printf("%d\n", n);
        else {
            int max = indices[1];
            for(int i = 2; i < size; ++i)
                max = max > indices[i] - indices[i - 2] ? max : indices[i] - indices[i - 2];
            printf("%d\n", max > n - indices[size - 2] ? max : n - indices[size - 2]);
        }
        free(indices);
    }
    free(buffer);
    return 0;
}
