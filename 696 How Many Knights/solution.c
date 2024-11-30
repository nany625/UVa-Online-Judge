#include <stdio.h>

int specialCase(int n) {
	if(n & 1)
		return 1;
	return n;
}

int main() {
	int M, N;
	while(scanf("%d %d", &M, &N) && M + N > 0) {
		if(M == 1)
			printf("%d knights may be placed on a %d row %d column board.\n", N, M, N);
		else if(N == 1)
			printf("%d knights may be placed on a %d row %d column board.\n", M, M, N);
		else if(M == 2)
			printf("%d knights may be placed on a %d row %d column board.\n", N + specialCase(N & 3), M, N);
		else if(N == 2)
			printf("%d knights may be placed on a %d row %d column board.\n", M + specialCase(M & 3), M, N);
		else
			printf("%d knights may be placed on a %d row %d column board.\n", M * N + 1 >> 1, M, N);
	}
	return 0;
}
