#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
	    long work = 0;
	    int curr = 0;
	    while(n--) {
	        short a;
	        scanf("%hd", &a);
	        curr += a;
	        work += abs(curr);
	    }
	    printf("%ld\n", work);
	}
	return 0;
}
