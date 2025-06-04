#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 2000000

typedef struct {
    int n, pfCount;  
} Answer;

bool isComposite[MAX_NUM + 1];
int *primes, size;
Answer answers[MAX_NUM + 1];

void eulerSieve() {
    answers[1].n = 1;
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            answers[n].pfCount = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
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
