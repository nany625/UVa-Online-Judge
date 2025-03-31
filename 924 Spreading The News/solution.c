#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int E;
    scanf("%d", &E);
    int friends[E][15], N[E];
    for(int i = 0; i < E; ++i) {
        scanf("%d", &N[i]);
        for(int j = 0; j < N[i]; ++j)
            scanf("%d", &friends[i][j]);
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int emp;
        scanf("%d", &emp);
        bool heard[E];
        memset(heard, 0, sizeof(heard));
        heard[emp] = true;
        int *curr = (int*)malloc(sizeof(int)), currSize = 1, M = 0, D = 0, currDay = 1;
        curr[0] = emp;
        while(currSize > 0) {
            int *next = NULL, nextSize = 0;
            for(int i = 0; i < currSize; ++i) {
                for(int j = 0; j < N[curr[i]]; ++j) {
                    if(!heard[friends[curr[i]][j]]) {
                        next = (int*)realloc(next, (nextSize + 1) * sizeof(int));
                        next[nextSize++] = friends[curr[i]][j];
                        heard[friends[curr[i]][j]] = true;
                    }
                }
            }
            if(M < nextSize) {
                M = nextSize;
                D = currDay;
            }
            curr = (int*)realloc(curr, nextSize * sizeof(int));
            for(int i = 0; i < nextSize; ++i)
                curr[i] = next[i];
            currSize = nextSize;
            ++currDay;
            free(next);
        }
        if(D == 0)
            puts("0");
        else
            printf("%d %d\n", M, D);
        free(curr);
    }
	return 0;
}
