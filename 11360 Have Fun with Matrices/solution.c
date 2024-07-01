#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
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
            char operation[10];
            scanf("%s", operation);
            if(strcmp(operation, "row") == 0) {
                int a,b;
                scanf("%d %d", &a, &b);
                char temp[N + 1];
                strcpy(temp, matrix[a - 1]);
                strcpy(matrix[a - 1], matrix[b - 1]);
                strcpy(matrix[b - 1], temp);
            } else if(strcmp(operation, "col") == 0) {
                int a, b;
                scanf("%d %d", &a, &b);
                for(int j = 0; j < N; ++j) {
                    char temp = matrix[j][a - 1];
                    matrix[j][a - 1] = matrix[j][b - 1];
                    matrix[j][b - 1] = temp;
                }
            } else if(strcmp(operation, "inc") == 0) {
                for(int j = 0; j < N; ++j) {
                    for(int k = 0; k < N; ++k)
                        matrix[j][k] = (char)((matrix[j][k] - '0' + 1) % 10 + '0');
                }
            } else if(strcmp(operation, "dec") == 0) {
                for(int j = 0; j < N; ++j) {
                    for(int k = 0; k < N; ++k)
                        matrix[j][k] = (char)((matrix[j][k] - '0' + 9) % 10 + '0');
                }
            } else if(strcmp(operation, "transpose") == 0) {
                for(int j = 0; j < N; ++j) {
                    for(int k = 1; k < N - j; ++k) {
                        char temp = matrix[j][j + k];
                        matrix[j][j + k] = matrix[j + k][j];
                        matrix[j + k][j] = temp;
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
