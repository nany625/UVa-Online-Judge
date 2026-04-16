#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAXN >> 7) + 1];
int *primes, size;
long answers[MAXN + 1];

void eulerSieve() {
    for(int n = 3; n <= MAXN >> 1; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            int tempSum = 1, term = 2;
            while(1) {
                int op = term * n;
                if(op > MAXN)
                    break;
                tempSum += term;
                answers[op] = tempSum * (1 + n) - (op << 1);
                term <<= 1;
            }
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN >> 1; ++i) {
            SET(temp >> 1);
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    for(int i = 11; i <= MAXN; ++i)
        answers[i] += answers[i - 1];
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d %ld\n", n, answers[n]);
    return 0;
}
