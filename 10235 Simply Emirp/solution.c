#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
    if(n <= 3)
        return n > 1;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    int limit = sqrt(n);
    for(int i = 5; i <= limit; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        if(!isPrime(N))
            printf("%d is not prime.\n", N);
        else {
            int reverse = 0, temp = N;
            while(temp > 0) {
                reverse = 10 * reverse + temp % 10;
                temp /= 10;
            }
            if(reverse != N && isPrime(reverse))
                printf("%d is emirp.\n", N);
			else
				printf("%d is prime.\n", N);
        }
    }
    return 0;
}
