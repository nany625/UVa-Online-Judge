#include <stdio.h>
#include <string.h>

int lastDigit[] = {
    0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 
    7, 8, 4, 7, 3, 8, 4, 1, 5, 4,
};

int main() {
    char N[102], quotient[102];
    while(scanf("%s", N) && N[0] != '0') {
        int dividend = 0, len = strlen(N);
        for(int i = 0; i < len; ++i) {
            dividend = 10 * dividend + N[i] - '0';
            quotient[i] = dividend / 20 + '0';
            dividend %= 20;
        }
        printf("%d\n", ((quotient[len - 1] - '0') * 4 + lastDigit[dividend]) % 10);
    }
	return 0;
}
