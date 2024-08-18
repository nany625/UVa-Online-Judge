#include <stdio.h>

int main() {
    long n;
    while(scanf("%ld", &n) == 1)
        printf("%ld\n", (n / 2 + 1) * (n / 2 + 2) / 2);
	return 0;
}
