#include <stdio.h>
#include <math.h>

int main() {
	int X = 0, N;
	while(scanf("%d", &N) && N >= 0)
		printf("Case %d: %d\n", ++X, (int)ceil(log2(N)));
	return 0;
}
