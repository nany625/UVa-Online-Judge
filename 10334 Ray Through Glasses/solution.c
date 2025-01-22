#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FIBONACCI_SIZE 1000

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fib[MAX_FIBONACCI_SIZE + 1];

void initFibonacci() {
    fib[0].number = strdup("1");
    fib[1].number = strdup("2");
    fib[0].digits = fib[1].digits = 1;
    for(int i = 2; i <= MAX_FIBONACCI_SIZE; ++i) {
        fib[i].number = (char*)malloc((fib[i - 1].digits + 1) * sizeof(char));
        memset(fib[i].number, '0', fib[i - 1].digits + 1);
        short j;
        for(j = 0; j < fib[i - 1].digits; ++j) {
        	fib[i].number[j + 1] += (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') / 10;
        	fib[i].number[j] = (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') % 10 + '0';
        }
        fib[i].digits = j + (fib[i].number[j] - '0');
    }
}

int main() {
    initFibonacci();
    int n;
    while(scanf("%d", &n) == 1) {
        for(int i = fib[n].digits - 1; i >= 0; --i)
            putchar(fib[n].number[i]);
        putchar('\n');
    }
    for(int i = 0; i <= MAX_FIBONACCI_SIZE; ++i)
        free(fib[i].number);
    return 0;
}
