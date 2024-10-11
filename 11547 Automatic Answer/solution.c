#include <stdio.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    printf("%d\n", abs((n * 63 + 7492) * 5 - 498) / 10 % 10);
	}
	return 0;
}
