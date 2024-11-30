#include <stdio.h>

int specialCase(int n) {
	if(n & 1)
		return 1;
	return n;
}

int solve(int M, int N) {
	if(M > N) {
		int temp = M;
		M = N;
		N = temp;
	}
	if(M == 0)
		return 0;
	if(M == 1)
		return N;
	if(M == 2)
		return N + specialCase(N & 3);
	return M * N + 1 >> 1;
}

int main() {
	int M, N;
	while(scanf("%d %d", &M, &N) && M + N > 0)
		printf("%d knights may be placed on a %d row %d column board.\n", solve(M, N), M, N);
	return 0;
}
