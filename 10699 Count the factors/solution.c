#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 997
#define MAX_PRIME_SIZE 168

bool isComposite[MAX_NUM + 1];
short primes[MAX_PRIME_SIZE] = {2};
int count = 1;

int main() {
    for(short i = 3; count < MAX_PRIME_SIZE; i += 2) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= 31) {
                for(short j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int num;
    while(scanf("%d", &num) && num != 0) {
        printf("%d : ", num);
        short limit = sqrt(num);
        int pfCount = 0;
        for(int i = 0; i < MAX_PRIME_SIZE && primes[i] <= limit; ++i) {
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
