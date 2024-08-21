#include <stdio.h>
#define KUTI 10000000
#define LAKH 100000
#define HAJAR 1000
#define SHATA 100

void split(long n) {
    if(n >= KUTI) {
        split(n / KUTI);
        fputs(" kuti", stdout);
        n %= KUTI;
    }
    if(n >= LAKH) {
        split(n / LAKH);
        fputs(" lakh", stdout);
        n %= LAKH;
    }
    if(n >= HAJAR) {
        split(n / HAJAR);
        fputs(" hajar", stdout);
        n %= HAJAR;
    }
    if(n >= SHATA) {
        split(n / SHATA);
        fputs(" shata", stdout);
        n %= SHATA;
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
