#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        long n;
        scanf("%ld", &n);
        printf("%ld\n", ((long)(1 + sqrt(1 + (n << 3))) >> 1) - 1);
    }
	return 0;
}
