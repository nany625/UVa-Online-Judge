#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 331
#define MAX_PRIME_SIZE 67

bool isComposite[MAX_NUM + 1];
short primes[MAX_PRIME_SIZE] = {2};
int count = 1;

int main() {
    for(short i = 3; count < MAX_PRIME_SIZE; i += 2) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= 31) {
                for(short j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
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
                for(int j = 0; j < MAX_PRIME_SIZE && primes[j] < trans[step - 1][i] && !found; ++j) {
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
