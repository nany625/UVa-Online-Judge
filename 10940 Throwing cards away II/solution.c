#include <stdio.h>
#include <math.h>

int main() {
	int n;
	while(scanf("%d", &n) && n != 0)
	    printf("%d\n", n == 1 ? 1 : n - (1 << (int)log2(n - 1)) << 1);
	return 0;
}
