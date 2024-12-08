#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_NUM 2000

bool isComposite[MAX_NUM + 1] = {true, true};

void eratosthenesSieve() {
    for(short n = 2; n <= MAX_NUM; ++n) {
        if(n <= 44 && !isComposite[n]) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                isComposite[i] = true;
        }
    }
}

int main() {
    eratosthenesSieve();
    int T;
    scanf("%d", &T);
    char buffer[MAX_NUM + 1];
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
