#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 20000000

bool isComposite[MAX_NUM + 1];
int twinPrimes[100000], count = 1;

int main() {
    twinPrimes[0] = 3;
    for(int i = 5; i <= MAX_NUM; i += 4) {
        if(!isComposite[i] && i <= 4472) {
            for(int j = i * i; j <= MAX_NUM; j += i << 1)
                isComposite[j] = true;
        }
        i += 2;
        if(!isComposite[i] && i <= 4472) {
            for(int j = i * i; j <= MAX_NUM; j += i << 1)
                isComposite[j] = true;
        }
        if(!isComposite[i - 2] && !isComposite[i])
            twinPrimes[count++] = i - 2;
    }
    int S;
    while(scanf("%d", &S) == 1)
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
	return 0;
}
