#include <stdio.h>
#include <math.h>

void split(long n) {
    if(n >= pow(10, 7)) {
        split(n / pow(10, 7));
        fputs(" kuti", stdout);
        n %= (long)pow(10, 7);
    }
    if(n >= pow(10, 5)) {
        split(n / pow(10, 5));
        fputs(" lakh", stdout);
        n %= (long)pow(10, 5);
    }
    if(n >= pow(10, 3)) {
        split(n / pow(10, 3));
        fputs(" hajar", stdout);
        n %= (long)pow(10, 3);
    }
    if(n >= pow(10, 2)) {
        split(n / pow(10, 2));
        fputs(" shata", stdout);
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
