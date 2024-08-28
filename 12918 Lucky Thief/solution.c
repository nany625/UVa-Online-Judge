#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%ld\n", (long)((m << 1) - n - 1) * n >> 1);
	}
	return 0;
}
