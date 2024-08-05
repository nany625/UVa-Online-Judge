#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *correct = NULL, *student = NULL, **L = NULL;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        char *token = strtok(buffer, " ");
        int temp = atoi(token);
        token = strtok(NULL, " ");
        if(!token) {
            n = temp;
            correct = (int*)realloc(correct, n * sizeof(int));
            for(int i = 1; i <= n; ++i) {
                scanf("%d", &temp);
                correct[temp - 1] = i;
            }
            L = (int**)realloc(L, (n + 1) * sizeof(int*));
            for(int i = 0; i <= n; ++i) 
                L[i] = (int*)realloc(L[i], (n + 1) * sizeof(int));
            memset(L[0], n + 1, 0);
            for(int i = 1; i <= n; ++i)
                L[i][0] = 0;
            getchar();
        } else {
            student = (int*)realloc(student, n * sizeof(int));
            student[temp - 1] = 1;
            student[atoi(token) - 1] = 2;
            int count = 2;
            token = strtok(NULL, " ");
            while(token) {
                student[atoi(token) - 1] = ++count;
                token = strtok(NULL, " ");
            }
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(correct[i - 1] == student[j - 1])
                        L[i][j] = L[i - 1][j - 1] + 1;
                    else
                        L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
                }
            }
            printf("%d\n", L[n][n]);
        }
    }
    free(correct);
    free(student);
    for(int i = 0; i <= n; ++i)
        free(L[i]);
    free(L);
    free(buffer);
	return 0;
}
