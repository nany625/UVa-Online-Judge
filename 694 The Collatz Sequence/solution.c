#include <stdio.h>

int main() {
    long A;
    int cases = 0, L;
    while(scanf("%ld %d", &A, &L) && A >= 0 && L >= 0) {
        printf("Case %d: A = %ld, limit = %d, number of terms = ", ++cases, A, L);
        int terms = 0;
        while(A != 1 && A <= L) {
            ++terms;
            A = A % 2 == 0 ? A / 2 : 3 * A + 1;
        }
        printf("%d\n", terms + (A == 1));
    }
	return 0;
}
