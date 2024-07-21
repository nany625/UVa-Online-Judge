#include <stdio.h>

long reverse(long n) {
    long result = 0;
    while(n > 0) {
        result = 10 * result + n % 10;
        n /= 10;
    }
    return result;
}

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
	    long P;
	    scanf("%ld", &P);
	    int count = 0;
	    long reverseP = reverse(P);
	    do {
	        ++count;
	        P += reverseP;
	        reverseP = reverse(P);
	    } while(P != reverseP);
	    printf("%d %ld\n", count, P);
	}
	return 0;
}
