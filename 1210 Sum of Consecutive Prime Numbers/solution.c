#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 10000
#define MAX_PRIME_SIZE 1229

bool isComposite[MAX_NUM + 1];
short primes[MAX_PRIME_SIZE] = {2}, primesSumCount[MAX_NUM + 1];
int count = 1;

int main() {
    for(short i = 3; count < MAX_PRIME_SIZE; i += 2) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= 100) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    for(int i = 0; i < MAX_PRIME_SIZE; ++i) {
        int sum = 0;
        for(int j = i; j < MAX_PRIME_SIZE && (sum += primes[j]) <= MAX_NUM; ++j)
            ++primesSumCount[sum];
    }
    int num;
    while(scanf("%d", &num) && num != 0)
        printf("%d\n", primesSumCount[num]);
	return 0;
}
