#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 10007
#define EPS 1e-6

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes, ppCount[MAX_NUM + 1] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    40, 40
};
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

bool producePrime(int n) {
    int num = n * n + n + 41;
    for(int i = 13; primes[i] < n; ++i) {
        if(num % primes[i] == 0)
            return false;
    }
	return true;
}


int main() {
    eulerSieve();
	for(int i = 42; i <= MAX_NUM; ++i) {
	    ppCount[i] = ppCount[i - 1];
	    if(i % 41 == 0 || (i + 1) % 41 == 0)
	        continue;
	    ppCount[i] += producePrime(i);
	}
    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
        printf("%.2f\n", 100.0 * (ppCount[b] - ppCount[a] + (a == 0 || ppCount[a] > ppCount[a - 1])) / (b - a + 1) + EPS);
    free(primes);
    return 0;
}
