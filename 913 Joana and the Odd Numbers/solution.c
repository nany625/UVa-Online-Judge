#include <stdio.h>

int main() {
	long N;
	while(scanf("%ld", &N) == 1)
		printf("%ld\n", 3 * N * N + 6 * N - 15 >> 1);
	return 0;
}
