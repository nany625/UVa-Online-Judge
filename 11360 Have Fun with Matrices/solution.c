#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char operation[10];
    for(int i = 1; i <= T; ++i) {
        printf("Case #%d\n", i);
        int N;
        scanf("%d", &N);
        char matrix[N][N + 1];
        for(int j = 0; j < N; ++j)
            scanf("%s", matrix[j]);
        int M;
        scanf("%d", &M);
        while(M--) {
            scanf("%s", operation);
            int a, b;
            char temp;
            switch(operation[0]) {
                case 'r': {
                    scanf("%d %d", &a, &b);
                    char *token = strdup(matrix[a - 1]);
                    strcpy(matrix[a - 1], matrix[b - 1]);
                    strcpy(matrix[b - 1], token);
                    free(token);
                    break;
                }
                case 'c': {
                    scanf("%d %d", &a, &b);
                    for(int j = 0; j < N; ++j) {
                        temp = matrix[j][a - 1];
                        matrix[j][a - 1] = matrix[j][b - 1];
                        matrix[j][b - 1] = temp;
                    }
                    break;
                }
                case 'i': {
                    for(int j = 0; j < N; ++j) {
                        for(int k = 0; k < N; ++k)
                            matrix[j][k] = (char)((matrix[j][k] - '0' + 1) % 10 + '0');
                    }
                    break;
                }
                case 'd': {
                    for(int j = 0; j < N; ++j) {
                        for(int k = 0; k < N; ++k)
                            matrix[j][k] = (char)((matrix[j][k] - '0' + 9) % 10 + '0');
                    }
                    break;
                }
                case 't': {
                    for(int j = 0; j < N; ++j) {
                        for(int k = 1; k < N - j; ++k) {
                            temp = matrix[j][j + k];
                            matrix[j][j + k] = matrix[j + k][j];
                            matrix[j + k][j] = temp;
                        }
                    }
                }
            }
        }
        for(int j = 0; j < N; ++j)
            printf("%s\n", matrix[j]);
        puts("");
    }
    return 0;
}
