#include <stdio.h>
#include <stdbool.h>

int main() {
    int B, N;
    while(scanf("%d %d", &B, &N) && B != 0) {
        int reserves[B + 1];
        for(int i = 1; i <= B; ++i)
            scanf("%d", &reserves[i]);
        while(N--) {
            int D, C, V;
            scanf("%d %d %d", &D, &C, &V);
            reserves[D] -= V;
            reserves[C] += V;
        }
        bool possible = true;
        for(int i = 1; i <= B && possible; ++i)
            possible = reserves[i] >= 0;
        puts(possible ? "S" : "N");
    }
	return 0;
}
