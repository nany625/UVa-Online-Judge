#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_NUM 1040

bool isComposite[MAX_NUM + 1];

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(!isComposite[i] && i <= 32) {
            for(int j = i * i; j <= MAX_NUM; j += i)
                isComposite[j] = true;
        }
    }
    char L[21];
    while(scanf("%s", L) == 1) {
        int len = strlen(L), sum = 0;
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
