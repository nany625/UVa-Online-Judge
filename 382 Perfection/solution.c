#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

short primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
    233, 239, 241
};

int sumOfDivisors(int n) {
    int sum = 1, limit = sqrt(n);
    for(int i = 0; i < 53 && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            int tempSum = 1, term = 1;
            do {
                tempSum += term *= primes[i];
                n /= primes[i];
            } while(n % primes[i] == 0);
            sum *= tempSum;
            limit = sqrt(n);
        }
    }
    if(n > 1)
        sum *= (1 + n);
    return sum;
}

int main() {
	char *buffer = NULL;
	size_t bufsize = 0;
	puts("PERFECTION OUTPUT");
	while(getline(&buffer, &bufsize, stdin) != -1) {
	    char *token = strtok(buffer, " ");
    	int n;
    	while(token && (n = atoi(token)) != 0) {
    	    if(n > 6 && n % 6 == 0)
    	        printf("%5d  ABUNDANT\n", n);
    	    else {
    	        int sum = sumOfDivisors(n) - n;
    	        if(sum < n)
    	            printf("%5d  DEFICIENT\n", n);
    	        else if(sum == n)
    	            printf("%5d  PERFECT\n", n);
    	        else
    	            printf("%5d  ABUNDANT\n", n);
    	    }
    	    token = strtok(NULL, " ");
    	}
	}
	puts("END OF OUTPUT");
	free(buffer);
	return 0;
}
