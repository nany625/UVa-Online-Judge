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
    int k;
    while(scanf("%d", &k) && k != 0) {
        if(isPrime(k))
            puts("0");
        else {
        	k -= (k + 1) % 2;
            int i = 0, j = 0;
            while(!isPrime(k - i))
                i += 2;
            do {
                j += 2;
            } while(!isPrime(k + j));
            printf("%d\n", i + j);
        }
    }
    return 0;
}
