#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 32611

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes;
int size = 1;

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 1, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int josephus(int n, int index) {
    return n == 1 ? 0 : (josephus(n - 1, index + 1) + primes[index]) % n;
}

int main() {
    eulerSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d\n", josephus(n, 0) + 1);
    free(primes);
	return 0;
}
