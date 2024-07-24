#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 2000
#define MAX_PRIME_SIZE 303

bool isComposite[MAX_NUM + 1] = {true, true};
short primes[MAX_PRIME_SIZE] = {};
int count = 0;

int main() {
    for(short i = 2; count < MAX_PRIME_SIZE; ++i) {
        if(!isComposite[i]) {
            primes[count++] = i;
            if(i <= 44) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int T;
    scanf("%d", &T);
    char buffer[2001];
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
            if(!isComposite[frequency[j]]) {
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
