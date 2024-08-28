#include <stdio.h>

int main() {
    long n;
    while(scanf("%ld", &n) == 1)
        printf("%ld\n", ((n >> 1) + 1) * ((n >> 1) + 2) >> 1);
	return 0;
}
