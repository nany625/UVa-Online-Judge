#include <stdio.h>

int main() {
    long M, N;
    while(scanf("%ld %ld", &M, &N) && M != 0) {
        if(M > N) {
            long temp = M;
            M = N;
            N = temp;
        }
        long vertical = M * (M - 1) * N;
        long horizontal = N * (N - 1) * M;
        long diagonal = (M * (M - 1) * (M - 2) << 3) / 6 + (M * (M - 1) * (N - M + 1) << 1);
        printf("%ld\n", vertical + horizontal + diagonal);
    }
	return 0;
}
