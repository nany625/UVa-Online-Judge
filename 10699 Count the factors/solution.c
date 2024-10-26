#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000

bool isComposite[MAX_NUM + 1];
short *primes = NULL;
int size = 1;

int main() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = i;
            if(i <= 31) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int num;
    while(scanf("%d", &num) && num != 0) {
        printf("%d : ", num);
        short limit = sqrt(num);
        int pfCount = 0;
        for(int i = 0; i < size && primes[i] <= limit; ++i) {
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
    free(primes);
    return 0;
}
