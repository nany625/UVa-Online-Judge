#include <stdio.h>

int main() {
    int M = 0, N;
    while(scanf("%d", &N) == 1) {
        int S[N];
        for(int i = 0; i < N; ++i)
            scanf("%d", &S[i]);
        long P = 0, curr;
        for(int i = 0; i < N; ++i) {
            curr = S[i];
            P = P > curr ? P : curr;
            for(int j = i + 1; j < N; ++j) {
                curr *= S[j];
                P = P > curr ? P : curr;
            }
        }
        printf("Case #%d: The maximum product is %ld.\n\n", ++M, P);
    }
    return 0;
}
