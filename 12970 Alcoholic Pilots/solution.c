#include <stdio.h>

long GCD(long i, long j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    int cases = 0;
    long v1, d1, v2, d2;
    while(scanf("%ld %ld %ld %ld", &v1, &d1, &v2, &d2) && v1 != 0 && d1 != 0 && v2 != 0 && d2 != 0) {
        printf("Case #%d: %s\nAvg. arrival time: ", ++cases, d1 * v2 < d2 * v1 ? "You owe me a beer!" : "No beer for the captain.");
        long numerator = d1 * v2 + v1 * d2, denominator = 2 * v1 * v2;
        long temp = GCD(numerator, denominator);
        numerator /= temp;
        denominator /= temp;
        if(denominator > 1)
			printf("%ld/%ld\n", numerator, denominator);
		else
			printf("%ld\n", numerator / denominator);

    }
	return 0;
}
