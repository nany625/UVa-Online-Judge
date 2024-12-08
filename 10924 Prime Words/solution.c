#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_NUM 1040

bool isComposite[MAX_NUM + 1];

void eratosthenesSieve() {
    for(short n = 2; n <= MAX_NUM; ++n) {
        if(n <= 32 && !isComposite[n]) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                isComposite[i] = true;
        }
    }
}

int main() {
    eratosthenesSieve();
    char L[21];
    while(scanf("%s", L) == 1) {
        int sum = 0, len = strlen(L);
        for(int i = 0; i < len; ++i) {
            if(isupper(L[i]))
                sum += L[i] - 'A' + 27;
            else if(islower(L[i]))
                sum += L[i] - 'a' + 1;
        }
        puts(isComposite[sum] ? "It is not a prime word." : "It is a prime word.");
    }
    return 0;
}
