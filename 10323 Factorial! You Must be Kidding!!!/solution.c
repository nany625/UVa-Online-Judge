#include <stdio.h>

long fac[14] = {1};

int main() {
    for(int n = 1; n < 14; ++n)
        fac[n] = fac[n - 1] * n;
    int n;
    while(scanf("%d", &n) == 1) {
        if(n < 0)
            puts(n & 1 ? "Overflow!" : "Underflow!");
        else if(n <= 7)
            puts("Underflow!");
        else if(n <= 13)
            printf("%ld\n", fac[n]);
        else
            puts("Overflow!");
    }
	return 0;
}
