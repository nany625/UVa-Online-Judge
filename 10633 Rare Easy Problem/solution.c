#include <stdio.h>

int main() {
    unsigned long n;
    while(scanf("%lu", &n) && n != 0) {
        long temp = n * 10 / 9;
        if(n % 9 == 0)
            printf("%ld %ld\n", temp - 1, temp);
        else
            printf("%ld\n", temp);
    }
    return 0;
}
