#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
	    int e, f, c;
	    scanf("%d %d %d", &e, &f, &c);
	    double ans = (e + f - c) / (c - 1.0);
	    printf("%d\n", ans >= 0 ? (int)ans + 1 : 0);
	}
	return 0;
}
