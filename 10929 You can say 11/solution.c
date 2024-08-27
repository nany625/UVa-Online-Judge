#include <stdio.h>
#include <string.h>

int main() {
	char N[1001];
	while(scanf("%s", N) && N[0] != '0') {
	    int sum = 0, len = strlen(N);
	    for(int i = 0; i < len; ++i) {
	        if(i & 1)
	            sum -= N[i] - '0';
	        else
	            sum += N[i] - '0';
	    }
	    printf("%s is %sa multiple of 11.\n", N, sum % 11 == 0 ? "" : "not ");
	}
	return 0;
}
