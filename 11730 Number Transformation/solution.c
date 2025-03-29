#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    while(scanf("%d %d", &S, &T) && S != 0) {
        if(S == T)
            printf("Case %d: 0\n", ++cases);
        else {
            short *curr = (short*)malloc(sizeof(short));
            curr[0] = S;
            int currSize = 1, step = 1;
            bool visited[T + 1], found = false;
            memset(visited, 0, sizeof(visited));
            while(currSize > 0 && !found) {
                short *next = NULL;
                int nextSize = 0;
                for(int i = 0; i < currSize && !found; ++i) {
                    for(int j = 0; j < 67 && primes[j] < curr[i] && !found; ++j) {
                        if(curr[i] % primes[j] == 0) {
                            if(curr[i] + primes[j] == T) {
                                printf("Case %d: %d\n", ++cases, step);
                                found = true;
                            } else if(curr[i] + primes[j] < T && !visited[curr[i] + primes[j]]) {
                                next = (short*)realloc(next, (nextSize + 1) * sizeof(short));
                                next[nextSize++] = curr[i] + primes[j];
                                visited[curr[i] + primes[j]] = true;
                            }
                        }
                    }
                }
                curr = (short*)realloc(curr, (nextSize) * sizeof(short));
                for(int i = 0; i < nextSize; ++i)
                    curr[i] = next[i];
                currSize = nextSize;
                ++step;
                free(next);
            }
            if(!found)
                printf("Case %d: -1\n", ++cases);
            free(curr);
        }
    }
	return 0;
}
