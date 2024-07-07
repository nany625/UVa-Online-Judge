#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
    if(n <= 3)
        return n > 1;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    int limit = sqrt(n);
    for(int i = 5; i <= limit; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        if(!isPrime(N))
            printf("%d is not prime.\n", N);
        else {
            int len = log10(N) + 1;
            char temp[len + 1];
            sprintf(temp, "%d", N);
            for(int i = 0; i < len / 2; ++i)
                swap(&temp[i], &temp[len - 1 - i]);
            int reverse = atoi(temp);
            if(reverse != N && isPrime(reverse))
                printf("%d is emirp.\n", N);
			else
				printf("%d is prime.\n", N);
        }
    }
    return 0;
}
