#include <stdio.h>

int main() {
    int a, b, c, d, L;
	while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) && (a != 0 || b != 0 || c != 0 || d != 0 || L != 0)) {
	    int count = 0;
	    for(int x = 0; x < d; ++x)
	        count += (a * x * x + b * x + c) % d == 0;
	    count *= L / d;
	    do {
	        count += (a * L * L + b * L + c) % d == 0;
	    } while(L-- % d != 0);
	    printf("%d\n", count);
	}
    return 0;
}
