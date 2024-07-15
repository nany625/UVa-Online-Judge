#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

int main() {
    int T;
    scanf("%d", &T);
    char buffer[2001];
    for(int i = 1; i <= T; ++i) {
        printf("Case %d: ", i);
        scanf("%s", buffer);
        short count[62] = {};
        int len = strlen(buffer);
        for(int j = 0; j < len; ++j) {
            if(isdigit(buffer[j]))
                ++count[buffer[j] - '0'];
            else if(isupper(buffer[j]))
                ++count[buffer[j] - 'A' + 10];
            else if(islower(buffer[j]))
                ++count[buffer[j] - 'a' + 36];
        }
        bool empty = true;
        for(int j = 0; j < 62; ++j) {
            if(isPrime(count[j])) {
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
