#include <stdio.h>
#include <math.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int sumOfDivisors(int n) {
    int sum = 1, limit = sqrt(n);
    for(int i = 0; i < 11 && primes[i] <= limit; ++i) {
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
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(n % 2 == 1) {
	        puts("deficient");
	        continue;
	    }
	    int sum = sumOfDivisors(n) - n;
	    if(sum < n)
	        puts("deficient");
	    else if(sum == n)
	        puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}
