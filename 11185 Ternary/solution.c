#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    while(scanf("%d", &N) && N >= 0) {
        if(N == 0)
            puts("0");
        else {
            int *digits = NULL, size = 0;
            while(N > 0) {
                digits = (int*)realloc(digits, (size + 1) * sizeof(int));
                digits[size++] = N % 3;
                N /= 3;
            }
            for(int i = size - 1; i >= 0; --i)
                printf("%d", digits[i]);
            putchar('\n');
            free(digits);
        }
    }
    return 0;
}
