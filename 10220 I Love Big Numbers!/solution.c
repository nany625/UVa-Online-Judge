#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *number;
    short digits;
} Factorial;

Factorial fac[1000];

int main() {
    fac[0].number = strdup("1");
    fac[0].digits = 1;
    char temp[4];
    for(int i = 1; i < 1000; ++i) {
        int num = i + 1;
        while(num % 10 == 0)
            num /= 10;
        sprintf(temp, "%d", num);
        int len = strlen(temp);
        fac[i].number = (char*)malloc((fac[i - 1].digits + len + 1) * sizeof(char));
        memset(fac[i].number, '0', (fac[i - 1].digits + len) * sizeof(char));
        fac[i].number[fac[i - 1].digits + len] = '\0';
        for(int j = len - 1; j >= 0; --j) {
            for(int k = fac[i - 1].digits - 1; k >= 0; --k) {
                fac[i].number[j + k] += ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[j + k + 1] - '0') / 10;
                fac[i].number[j + k + 1] = ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[j + k + 1] - '0') % 10 + '0';
            }
        }
        fac[i].digits = fac[i - 1].digits + len - (fac[i].number[0] == '0');
        if(fac[i].number[0] == '0')
            memmove(fac[i].number, fac[i].number + 1, fac[i].digits * sizeof(char));
        while(fac[i].number[fac[i].digits - 1] == '0')
            --fac[i].digits;
    }
    int n;
    while(scanf("%d", &n) == 1) {
        int sumOfDigits = 0;
        for(int i = 0; i < fac[n - 1].digits; ++i)
            sumOfDigits += fac[n - 1].number[i] - '0';
        printf("%d\n", sumOfDigits);
    }
    for(int i = 0; i < 1000; ++i)
        free(fac[i].number);
    return 0;
}
