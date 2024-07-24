#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000
#define MAX_PRIME_SIZE 78498

bool isComposite[MAX_NUM + 1] = {true, true};
int primes[MAX_PRIME_SIZE] = {}, count = 0;

long sumOfDivisors(long n) {
    long sum = 1, limit = sqrt(n);
    for(int i = 0; i < MAX_PRIME_SIZE && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            long tempSum = 1, term = 1;
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
    int limit = sqrt(MAX_NUM);
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= limit) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int t;
	scanf("%d", &t);
	while(t--) {
	    long n;
	    scanf("%ld", &n);
	    if(n % 2 == 1) {
	        puts("deficient");
	        continue;
	    }
	    long sum = sumOfDivisors(n) - n;
	    if(sum < n)
	        puts("deficient");
	    else if(sum == n)
	        puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}
