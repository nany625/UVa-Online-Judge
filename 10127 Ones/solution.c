#include <stdio.h>

int main() {
	int n;
	while(scanf("%d",&n) == 1) {
	    int x = 0, remainder = 0;
		do {
		    remainder = (10 * remainder + 1) % n;
			++x;
		} while(remainder != 0);
		printf("%d\n", x);
	}
	return 0;
}
