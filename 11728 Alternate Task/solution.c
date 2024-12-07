#include <stdio.h>
#include <math.h>
#define MAX_NUM 1000

char primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
short table[MAX_NUM + 1];

short factorSum(short n) {
    short sum = 1, limit = sqrt(n), temp = n;
    for(int i = 0; i < 11 && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            short tempSum = 1, term = 1;
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
    for(short i = 1; i <= MAX_NUM; ++i) {
        short temp = factorSum(i);
        if(temp <= MAX_NUM)
            table[temp] = i;
    }
	int cases = 0, S;
	while(scanf("%d", &S) && S != 0)
	    printf("Case %d: %hd\n", ++cases, table[S] == 0 ? -1 : table[S]);
	return 0;
}
