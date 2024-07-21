#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int C;
    scanf("%d", &C);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(C--) {
        int N;
        scanf("%d", &N);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int grades[N], sum = 0;
        for(int i = 0; i < N; ++i) {
            sum += grades[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        int count = 0;
        for(int i = 0; i < N; ++i)
            count += grades[i] * N > sum;
        printf("%.3f%%\n", 100.0 * count / N);
    }
    free(buffer);
    return 0;
}
