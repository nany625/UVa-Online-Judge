#include <stdio.h>
#include <math.h>

void split(long n) {
    if(n >= pow(10, 7)) {
        split(n / pow(10, 7));
        printf(" kuti");
        n %= (long)pow(10, 7);
    }
    if(n >= pow(10, 5)) {
        split(n / pow(10, 5));
        printf(" lakh");
        n %= (long)pow(10, 5);
    }
    if(n >= pow(10, 3)) {
        split(n / pow(10, 3));
        printf(" hajar");
        n %= (long)pow(10, 3);
    }
    if(n >= pow(10, 2)) {
        split(n / pow(10, 2));
        printf(" shata");
        n %= (long)pow(10, 2);
    }
    if(n > 0)
        printf(" %ld", n);
}

int main() {
    long n;
    int cases = 0;
    while(scanf("%ld", &n) == 1) {
        printf("%4d.", ++cases);
        if(n == 0)
            puts(" 0");
        else {
            split(n);
            putchar('\n');
        }
    }
    return 0;
}
