#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FACTORIAL_SIZE 366

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fac[MAX_FACTORIAL_SIZE + 1];
char temp[4];

void initFactorial() {
	fac[0].number = strdup("1");
	fac[1].number = strdup("1");
    fac[0].digits = fac[1].digits = 1;
    for(int i = 2; i <= MAX_FACTORIAL_SIZE; ++i) {
        sprintf(temp, "%d", i);
        int len = strlen(temp);
        fac[i].number = (char*)malloc((fac[i - 1].digits + len + 1) * sizeof(char));
        memset(fac[i].number, '0', (fac[i - 1].digits + len) * sizeof(char));
        for(int j = len - 1; j >= 0; --j) {
            for(int k = 0; k < fac[i - 1].digits; ++k) {
                fac[i].number[len - j + k] += ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[len - 1 - j + k] - '0') / 10;
                fac[i].number[len - 1 - j + k] = ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[len - 1 - j + k] - '0') % 10 + '0';
            }
        }
        fac[i].digits = fac[i - 1].digits + len - (fac[i].number[fac[i - 1].digits + len - 1] == '0');
    }
}

int main() {
    initFactorial();
    int n;
    while(scanf("%d", &n) && n != 0) {
        printf("%d! --\n", n);
        int count[10] = {};
        for(int i = fac[n].digits - 1; i >= 0; --i)
            ++count[fac[n].number[i] - '0'];
        for(int i = 0; i < 10; ++i) {
            if(i % 5 == 0)
                printf("   (%d)%5d", i, count[i]);
            else if(i % 5 == 4)
                printf("    (%d)%5d\n", i, count[i]);
            else
                printf("    (%d)%5d", i, count[i]);
        }
    }
    for(int i = 0; i <= MAX_FACTORIAL_SIZE; ++i)
        free(fac[i].number);
    return 0;
}
