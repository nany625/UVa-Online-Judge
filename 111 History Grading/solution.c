#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *correct = NULL, *student = NULL, *L = NULL;
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
            L = (int*)malloc((n + 1) * sizeof(int));
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
            memset(L, 0, (n + 1) * sizeof(int));
            for(int i = 0; i < n; ++i) {
                int prev = 0;
                for(int j = 1; j <= n; ++j) {
                    temp = L[j];
                    if(correct[i] == student[j - 1])
                        L[j] = prev + 1;
                    else
                        L[j] = L[j] > L[j - 1] ? L[j] : L[j - 1];
                    prev = temp;
                }
            }
            printf("%d\n", L[n]);
        }
    }
    free(correct);
    free(student);
    free(L);
    free(buffer);
	return 0;
}
