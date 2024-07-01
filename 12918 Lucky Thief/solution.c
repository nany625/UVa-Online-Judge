#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%ld\n", (long)(2 * m - n - 1) * n / 2);
	}
	return 0;
}
