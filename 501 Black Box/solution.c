#include <stdio.h>
#define MAXM 30000

int A[MAXM];

int main() {
    int K;
    scanf("%d", &K);
    while(K--) {
        int M, N;
        scanf("%d %d", &M, &N);
        for(int i = 0; i < M; ++i)
            scanf("%d", &A[i]);
        int u, size = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &u);
            for(int j = size; j < u; ++j) {
                int num = A[j], k = j;
                while(k > 0 && num < A[k - 1]) {
                    A[k] = A[k - 1];
                    --k;
                }
                A[k] = num;
            }
            size = u;
            printf("%d\n", A[i]);
        }
        if(K)
            putchar('\n');
    }
	return 0;
}
