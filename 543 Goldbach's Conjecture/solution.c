#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 999999
#define MAX_PRIME_SIZE 78497

bool isComposite[MAX_NUM + 1];
int primes[MAX_PRIME_SIZE] = {}, count = 0;

int main() {
    for(int i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= 999) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int n;
    while(scanf("%d", &n) && n != 0) {
        int i = 0;
        while(isComposite[n - primes[i]])
            ++i;
        printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
    }
	return 0;
}
