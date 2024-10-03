#include <stdio.h>

int main() {
	int cases = 0, Z, I, M, L;
	while(scanf("%d %d %d %d", &Z, &I, &M, &L) && !(Z == 0 && I == 0 && M == 0 && L == 0)) {
	    short order[10000] = {}, count = 1;
	    do {
	        order[L] = count++;
	        L = (Z * L + I) % M;
	    } while(order[L] == 0);
	    printf("Case %d: %hd\n", ++cases, count - order[L]);
	}
	return 0;
}
