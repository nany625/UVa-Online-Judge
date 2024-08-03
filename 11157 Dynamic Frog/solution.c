#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char S;
    int M;
} Stone;

int main() {
    int T;
    char *buffer = NULL;
    size_t bufsize = 0;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N, D;
        scanf("%d %d", &N, &D);
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        Stone stones[N + 2];
        stones[0].M = 0;
        for(int i = 1; i <= N; ++i) {
            stones[i].S = token[0];
            stones[i].M = atoi(token + 2);
            token = strtok(NULL, " ");
        }
        stones[N + 1].M = D;
        int max = 0;
        for(int i = 1; i <= N; ++i) {
            switch(stones[i].S) {
                case 'B':
                    max = max > stones[i].M - stones[i - 1].M ? max : stones[i].M - stones[i - 1].M;
                    break;
                case 'S':
                    max = max > stones[i + 1].M - stones[i - 1].M ? max : stones[i + 1].M - stones[i - 1].M;
            }
        }
        max = max > D - stones[N].M ? max : D - stones[N].M;
        printf("Case %d: %d\n", i, max);
    }
    free(buffer);
	return 0;
}
