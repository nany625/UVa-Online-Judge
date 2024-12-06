#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 10000

bool isComposite[MAX_NUM + 1] = {true, true};
short *primes;
int size;

void eulerSieve() {
    for(short n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

bool isPrime(int n) {
    int limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
    eulerSieve();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int numbers[2][n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &numbers[0][i]);
            numbers[1][i] = numbers[0][i];
        }
        int length = 2;
        bool antiPrimed = true;
        while(antiPrimed && length <= n) {
            for(int i = 0; i <= n - length && antiPrimed; ++i) {
                numbers[1][i] += numbers[0][i + length - 1];
                if((numbers[1][i] <= MAX_NUM && !isComposite[numbers[1][i]]) || (numbers[1][i] > MAX_NUM && isPrime(numbers[1][i]))) {
                    printf("Shortest primed subsequence is length %d:", length);
                    for(int j = i; j < i + length; ++j)
                        printf(" %d", numbers[0][j]);
                    putchar('\n');
                    antiPrimed = false;
                } 
            }
            ++length;
        }
        if(antiPrimed)
            puts("This sequence is anti-primed.");
    }
    free(primes);
    return 0;
}
