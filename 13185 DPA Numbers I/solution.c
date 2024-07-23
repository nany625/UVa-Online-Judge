#include <stdio.h>
#include <math.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

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
	    int sum = 1, limit = sqrt(n);
	    for(int i = 0; primes[i] <= limit && sum <= n; ++i) {
	        if(n % primes[i] == 0) {
	            sum += primes[i] + n / primes[i];
	            for(int j = 0; primes[j] <= primes[i] && sum <= n; ++j) {
	                for(int factor = primes[i] * primes[j]; n % factor == 0 && factor <= limit && sum <= n; factor *= primes[j])
	                    sum += factor + n / factor;
	            }
	        }
	    }
	    if(limit == sqrt(n))
	        sum -= limit;
	    if(sum < n)
	        puts("deficient");
	    else if(sum == n)
	        puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}
