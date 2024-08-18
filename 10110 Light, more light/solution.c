#include <stdio.h>
#include <math.h>

int main() {
    long n;
    while(scanf("%ld", &n) && n != 0)
        puts(sqrt(n) == (int)sqrt(n) ? "yes" : "no");
	return 0;
}
