#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

short primes[295] = {2};
int count = 1;
bool table[1937] = {false, false, true};

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
    for(short i = 3; count < 295; i += 2) {
        if(isPrime(i)) {
            primes[count++] = i;
            table[i] = true;
        }
    }
    int T;
    scanf("%d", &T);
    char buffer[1937];
    for(int i = 1; i <= T; ++i) {
        printf("Case %d: ", i);
        scanf("%s", buffer);
        short frequency[62] = {};
        int len = strlen(buffer);
        for(int j = 0; j < len; ++j) {
            if(isdigit(buffer[j]))
                ++frequency[buffer[j] - '0'];
            else if(isupper(buffer[j]))
                ++frequency[buffer[j] - 'A' + 10];
            else if(islower(buffer[j]))
                ++frequency[buffer[j] - 'a' + 36];
        }
        bool empty = true;
        for(int j = 0; j < 62; ++j) {
            if(table[frequency[j]]) {
                if(j < 10)
                    putchar('0' + j);
                else if(j < 36)
                    putchar('A' + j - 10);
                else
                    putchar('a' + j - 36);
                empty = false;
            }
        }
        puts(empty ? "empty" : "");
    }
    return 0;
}
