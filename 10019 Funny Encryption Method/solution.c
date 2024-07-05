#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N;
	    scanf("%d", &N);
	    int temp = N, count = 0;
	    while(temp > 0) {
	        count += temp % 2;
	        temp /= 2;
	    }
	    printf("%d ", count);
	    count = 0;
	    while(N > 0) {
	        temp = N % 10;
	        while(temp > 0) {
    	        count += temp % 2;
    	        temp /= 2;
    	    }
    	    N /= 10;
	    }
	    printf("%d\n", count);
	}
	return 0;
}
