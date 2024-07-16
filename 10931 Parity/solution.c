#include <stdio.h>
#include <math.h>

int main() {
	int I;
	while(scanf("%d", &I) && I != 0) {
	    int len = log2(I) + 1, bitsSum = 0;
	    char binaryRep[len + 1];
	    binaryRep[len] = '\0';
	    for(int i = len - 1; i >= 0; --i) {
	        bitsSum += (binaryRep[i] = I % 2 + '0') - '0';
	        I /= 2;
	    }
	    printf("The parity of %s is %d (mod 2).\n", binaryRep, bitsSum);
	}
	return 0;
}
