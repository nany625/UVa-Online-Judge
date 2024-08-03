#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char S;
    int M;
} Stone;

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    for(int i = 1; i <= T; ++i) {
        int N, D;
        scanf("%d %d", &N, &D);
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        Stone stones[N + 2];
        stones[0].M = 0;
        for(int j = 1; j <= N; ++j) {
            stones[j].S = token[0];
            stones[j].M = atoi(token + 2);
            token = strtok(NULL, " ");
        }
        stones[N + 1].M = D;
        int max = 0;
        for(int j = 1; j <= N; ++j) {
            switch(stones[j].S) {
                case 'B':
                    max = max > stones[j].M - stones[j - 1].M ? max : stones[j].M - stones[j - 1].M;
                    break;
                case 'S':
                    max = max > stones[j + 1].M - stones[j - 1].M ? max : stones[j + 1].M - stones[j - 1].M;
            }
        }
        max = max > D - stones[N].M ? max : D - stones[N].M;
        printf("Case %d: %d\n", i, max);
    }
    free(buffer);
	return 0;
}
