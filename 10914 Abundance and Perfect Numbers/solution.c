#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 10000000

typedef struct {
    int n;
    long abun;
} Answer;

Answer *answers;
bool isComposite[(MAXN >> 2) + 1];
int answerSize, *primes, primeSize;

int compare(const void *a, const void *b) {
    return ((Answer*)a)->n > ((Answer*)b)->n;
}

void eulerSieve() {
    for(int n = 3; n <= MAXN >> 1; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (primeSize + 1) * sizeof(int));
            primes[primeSize++] = n;
            int tempSum = 1, term = 2;
            while(term * n <= MAXN) {
                tempSum += term;
                answers = (Answer*)realloc(answers, (answerSize + 1) * sizeof(Answer));
                answers[answerSize++] = {term * n, tempSum * (1 + n)};
                term <<= 1;
            }
        }
        for(int i = 0, temp; i < primeSize && (temp = primes[i] * n) <= MAXN >> 1; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int binarySearch(int key) {
    int left = 0, right = answerSize - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(answers[mid].n == key)
            return mid;
        if(answers[mid].n < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}

int main() {
    eulerSieve();
    qsort(answers, answerSize, sizeof(Answer), compare);
    answers[0].abun = 0;
    for(int i = 1; i < answerSize; ++i)
        answers[i].abun += answers[i - 1].abun - (answers[i].n << 1);
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d %ld\n", n, n <= 9 ? 0 : answers[binarySearch(n)].abun);
    free(primes);
    free(answers);
    return 0;
}
