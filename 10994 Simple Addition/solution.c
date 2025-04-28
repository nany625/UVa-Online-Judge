#include <stdio.h>

long solve(long n) {
    long ans = 0;
    while(n > 0) {
        int temp = n % 10;
        ans += (n /= 10) * 45 + (temp * (temp + 1) >> 1);
    }
    return ans;
}

int main() {
    long p, q;
    while(scanf("%ld %ld", &p, &q) && p >= 0)
        printf("%ld\n", solve(q) - solve(p - 1));
	return 0;
}
