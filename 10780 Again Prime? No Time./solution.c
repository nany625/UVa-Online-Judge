#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 9999

bool isComposite[MAX_NUM + 1];
short *primes, **table;
int size, pfCount[MAX_NUM + 1];

void eulerSieve() {
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!isComposite[n]) {
			primes = (short*)realloc(primes, (size + 1) * sizeof(short));
			primes[size++] = n;
		}
		for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
			isComposite[temp] = true;
			if(n % primes[i] == 0)
				break;
		}
	}
}

void initTable(int n) {
    table[n] = (short*)malloc(pfCount[n - 1] * sizeof(short));
    for(int i = 0; i < pfCount[n - 1]; ++i)
        table[n][i] = table[n - 1][i];
    pfCount[n] = pfCount[n - 1];
    if(!isComposite[n]) {
        table[n] = (short*)realloc(table[n], (pfCount[n] + 1) * sizeof(short));
        table[n][pfCount[n]++] = 1;
    } else {
        int temp = n;
        for(int i = 0; n > 1; ++i) {
            while(n % primes[i] == 0) {
                ++table[temp][i];
                n /= primes[i];
            }
        }
    }
}

int main() {
    eulerSieve();
    table = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(int n = 2; n <= MAX_NUM; ++n)
        initTable(n);
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        short m, n;
        scanf("%hd %hd", &m, &n);
        int min = MAX_NUM;
        for(int j = 0; j < pfCount[n] && min > 0 && m > 1; ++j) {
            if(m % primes[j] == 0) {
                int power = 0;
                do {
                    ++power;
                    m /= primes[j];
                } while(m % primes[j] == 0);
                min = min < table[n][j] / power ? min : table[n][j] / power;
            }
        }
        if(m > 1 || min == MAX_NUM || min == 0)
            printf("Case %d:\nImpossible to divide\n", i);
        else
            printf("Case %d:\n%d\n", i, min);
    }
    for(int i = 2; i <= MAX_NUM; ++i)
        free(table[i]);
    free(table);
    free(primes);
	return 0;
}
