#include <stdio.h>
#include <math.h>
#include <stdbool.h>

short primes[169] = {2};
int count = 1;

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
    for(short i = 3; count < 169; i += 2) {
        if(isPrime(i))
            primes[count++] = i;
    }
    int num;
    while(scanf("%d", &num) && num != 0) {
        printf("%d : ", num);
        short limit = sqrt(num);
        int pfCount = 0;
        for(int i = 0; num > 1 && primes[i] <= limit; ++i) {
            if(num % primes[i] == 0) {
                ++pfCount;
                do {
                    num /= primes[i];
                } while(num % primes[i] == 0);
                limit = sqrt(num);
            }
        }
        printf("%d\n", pfCount + (num > 1));
    }
    return 0;
}
