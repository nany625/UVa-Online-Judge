#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *number;
    short digits;
} Fib;

Fib *fib = (Fib*)malloc(2 * sizeof(Fib));
int size = 2;

int main() {
    fib[0].number = strdup("0");
    fib[0].digits = 1;
    fib[1].number = strdup("1");
    fib[1].digits = 1;
    while(fib[size - 1].digits <= 1000) {
        fib = (Fib*)realloc(fib, (size + 1) * sizeof(Fib));
        fib[size].number = (char*)malloc((fib[size - 1].digits + 1) * sizeof(char));
        memset(fib[size].number, '0', fib[size - 1].digits + 1);
        short i;
        for(i = 0; i < fib[size - 1].digits; ++i) {
        	fib[size].number[i + 1] += (fib[size].number[i] + fib[size - 1].number[i] + fib[size - 2].number[i] - 3 * '0') / 10;
        	fib[size].number[i] = (fib[size].number[i] + fib[size - 1].number[i] + fib[size - 2].number[i] - 3 * '0') % 10 + '0';
        }
        fib[size].digits = i + (fib[size].number[i] - '0');
        ++size;
    }
    bool reversed[size] = {};
    int number;
    while(scanf("%d", &number) == 1) {
        if(!reversed[number]) {
            for(int i = 0; i < fib[number].digits / 2; ++i) {
                char temp = fib[number].number[i];
                fib[number].number[i] = fib[number].number[fib[number].digits - 1 - i];
                fib[number].number[fib[number].digits - 1 - i] = temp;
            }
            reversed[number] = true;
        }
        printf("%.*s\n", fib[number].digits, fib[number].number);
    }
    for(int i = 0; i < size; ++i)
        free(fib[i].number);
    free(fib);
    return 0;
}
