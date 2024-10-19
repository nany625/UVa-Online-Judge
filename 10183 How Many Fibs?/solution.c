#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FIBONACCI_SIZE 478

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
    for(int i = 2; i <= MAX_FIBONACCI_SIZE; ++i) {
        if(fib[i].number[fib[i].digits] == '0')
            fib[i].number[fib[i].digits] = '\0';
        for(int j = (fib[i].digits >> 1) - 1; j >= 0; --j) {
            char temp = fib[i].number[j];
            fib[i].number[j] = fib[i].number[fib[i].digits - 1 - j];
            fib[i].number[fib[i].digits - 1 - j] = temp;
        }
    }
}

int binarySearch(char *key, int len) {
    int left = 0, right = MAX_FIBONACCI_SIZE;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        int cmp = fib[mid].digits == len ? strcmp(fib[mid].number, key) : fib[mid].digits > len ? 1 : -1;
        if(cmp == 0)
            return mid;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    initFibonacci();
    char a[102], b[102];
    while(scanf("%s %s", a, b) && (a[0] != '0' || b[0] != '0')) {
        int lenA = strlen(a), lenB = strlen(b);
        int posA = binarySearch(a, lenA), posB = binarySearch(b, lenB);
        printf("%d\n", posB - posA + (posB <= MAX_FIBONACCI_SIZE && strcmp(fib[posB].number, b) == 0));
    }
    for(int i = 0; i <= MAX_FIBONACCI_SIZE; ++i)
        free(fib[i].number);
    return 0;
}
