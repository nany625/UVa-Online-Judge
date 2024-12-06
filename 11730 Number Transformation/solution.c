#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 331

short primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
    283, 293, 307, 311, 313, 317, 331
};

int main() {
    int cases = 0, S, T;
    while(scanf("%d %d", &S, &T) && S != 0 && T != 0) {
        if(S == T) {
            printf("Case %d: 0\n", ++cases);
            continue;
        }
        short **trans = (short**)malloc(sizeof(short*));
        trans[0] = (short*)malloc(sizeof(short));
        trans[0][0] = S;
        int currSize = 1, step = 1;
        bool visited[T + 1], found = false;
        memset(visited, 0, sizeof(visited));
        while(currSize > 0 && !found) {
            trans = (short**)realloc(trans, (step + 1) * sizeof(short*));
            trans[step] = NULL;
            int nextSize = 0;
            for(int i = 0; i < currSize && !found; ++i) {
                for(int j = 0; j < 67 && primes[j] < trans[step - 1][i] && !found; ++j) {
                    if(trans[step - 1][i] % primes[j] == 0) {
                        if(trans[step - 1][i] + primes[j] == T) {
                            printf("Case %d: %d\n", ++cases, step);
                            found = true;
                        } else if(trans[step - 1][i] + primes[j] < T && !visited[trans[step - 1][i] + primes[j]]) {
                            trans[step] = (short*)realloc(trans[step], (nextSize + 1) * sizeof(short));
                            trans[step][nextSize++] = trans[step - 1][i] + primes[j];
                            visited[trans[step - 1][i] + primes[j]] = true;
                        }
                    }
                }
            }
            currSize = nextSize;
            ++step;
        }
        if(!found)
            printf("Case %d: -1\n", ++cases);
        for(int i = 0; i < step; ++i)
            free(trans[i]);
        free(trans);
    }
	return 0;
}
