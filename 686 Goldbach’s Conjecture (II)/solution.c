#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 32765

bool isComposite[MAX_NUM + 1];
short *primes, pairs[16382] = {1};
int size;

int main() {
    for(short i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
	        primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = i;
            if(i <= 181) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
	    }
    }
    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            int sum = primes[i] + primes[j];
            if(sum < 32768)
                ++pairs[(sum >> 1) - 2];
        }
    }
	int n;
	while(scanf("%d", &n) && n != 0)
		printf("%d\n", pairs[(n >> 1) - 2]);
    free(primes);
	return 0;
}
