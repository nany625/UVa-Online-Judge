#include <stdio.h>

char primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97
};

int main() {
	int N;
	while(scanf("%d", &N) && N != 0) {
	    printf("%3d! =", N);
		char count[25] = {};
		for(int i = 2; i <= N; ++i) {
		    int j = 0, temp = i;
		    while(temp > 1) {
		        if(temp % primes[j] == 0) {
		            ++count[j];
		            temp /= primes[j];
		        } else
		            ++j;
		    }
		}
		for(int i = 0; i < 25 && count[i] > 0; ++i) {
    		if(i == 15)
    		    printf("\n      ");
    		printf("%3d", count[i]);
		}
		puts("");
	}
	return 0;
}
