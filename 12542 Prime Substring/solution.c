#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 99999
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 5) + 1];
int *primes, size;

void eulerSieve() {
    SET(0);
    SET(1);
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!GET(n)) {
		    primes = (int*)realloc(primes, (size + 1) * sizeof(int));
			primes[size++] = n;
		}
		for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
			SET(temp);
			if(n % primes[i] == 0)
			    break;
		}
	}
}

int subNum(char *array, int start, int len) {
    int result = 0;
    for(int i = start; i < start + len; ++i)
        result = 10 * result + array[i] - '0';
    return result;
}

int main() {
    eulerSieve();
    char s[256];
    while(scanf("%s", s) && strcmp(s, "0") != 0) {
        int max = 0, len = strlen(s);
        bool found = false;
        for(int i = len < 5 ? len : 5; !found; --i) {
            for(int j = 0; j <= len - i; ++j) {
                int num = subNum(s, j, i);
                if(!GET(num)) {
                    max = max > num ? max : num;
                    found = true;
                }
            }
        }
        printf("%d\n", max);
    }
    free(primes);
	return 0;
}
