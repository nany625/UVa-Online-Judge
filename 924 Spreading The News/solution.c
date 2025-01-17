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
        int **spread = (int**)malloc(sizeof(int*)), currSize = 1, M = 0, D = 0, currDay = 1;
        spread[0] = (int*)malloc(sizeof(int));
        spread[0][0] = emp;
        while(currSize > 0) {
            spread = (int**)realloc(spread, (currDay + 1) * sizeof(int*));
            spread[currDay] = NULL;
            int nextSize = 0;
            for(int i = 0; i < currSize; ++i) {
                for(int j = 0; j < N[spread[currDay - 1][i]]; ++j) {
                    if(!heard[friends[spread[currDay - 1][i]][j]]) {
                        spread[currDay] = (int*)realloc(spread[currDay], (nextSize + 1) * sizeof(int));
                        spread[currDay][nextSize++] = friends[spread[currDay - 1][i]][j];
                        heard[friends[spread[currDay - 1][i]][j]] = true;
                    }
                }
            }
            if(M < nextSize) {
                M = nextSize;
                D = currDay;
            }
            currSize = nextSize;
            ++currDay;
        }
        if(D == 0)
            puts("0");
        else
            printf("%d %d\n", M, D);
        for(int i = 0; i < currDay; ++i)
            free(spread[i]);
        free(spread);
    }
	return 0;
}
