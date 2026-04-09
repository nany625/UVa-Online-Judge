#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 2000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

typedef struct {
    int n, pfCount;  
} Answer;

unsigned int mark[(MAX_NUM >> 5) + 1];
int *primes, size;
Answer answers[MAX_NUM + 1];

void eulerSieve() {
    answers[1].n = 1;
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!GET(n)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            answers[n].pfCount = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp);
            answers[temp].pfCount = answers[primes[i]].pfCount + answers[n].pfCount;
            if(n % primes[i] == 0)
                break;
        }
        answers[n].n = n;
    }
}

int compare(const void *a, const void *b) {
    return ((Answer*)a)->pfCount > ((Answer*)b)->pfCount;
}

int main() {
    eulerSieve();
    qsort(answers, MAX_NUM + 1, sizeof(Answer), compare);
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0)
        printf("Case %d: %d\n", ++cases, answers[n].n);
    free(primes);
	return 0;
}
