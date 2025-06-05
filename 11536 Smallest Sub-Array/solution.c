#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000000
#define MAXK 100

int X[MAXN + 1] = {0, 1, 2, 3}, prevPos[MAXK + 1];

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        if(K <= 3)
            printf("Case %d: %d\n", i, K);
        else if(M < K)
            printf("Case %d: sequence nai\n", i);
        else {
            memset(prevPos, 0, sizeof(prevPos));
            for(int j = 1; j <= 3; ++j)
                prevPos[j] = j;
            int min = N, count = 3;
            for(int j = 4; j <= N; ++j) {
                X[j] = (X[j - 1] + X[j - 2] + X[j - 3]) % M + 1;
                if(X[j] <= K) {
                    if(prevPos[X[j]] == 0)
                        ++count;
                    prevPos[X[j]] = j;
                    if(count == K) {
                        int start = prevPos[1];
                        for(int k = 2; k <= K; ++k)
                            start = start < prevPos[k] ? start : prevPos[k];
                        min = min < j - start + 1 ? min : j - start + 1;
                    }
                }
            }
            if(count == K)
                printf("Case %d: %d\n", i, min);
            else
                printf("Case %d: sequence nai\n", i);
        }
    }
	return 0;
}
